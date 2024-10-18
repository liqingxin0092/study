assume cs:code

stacks segment
              db 128 dup(0)
stacks ends

data segment              ;存放原来中断地址
            dw 0,0
data ends

code segment

       main:   
       ;{
               cli                                       ;不处理中断
               mov   ax,stacks
               mov   ss,ax
               mov   sp,128                              ;设置栈指针

               mov   ax,data
               mov   ds,ax                               ;初始化存放点段

               mov   ax,0
               mov   es,ax                               ;初始化中断向量表段

       ;将原来的int 9中断例程入口地址保存在ds:[0],ds:[2]中:
               push  es:[9*4]
               pop   ds:[0]
               push  es:[9*4+2]
               pop   ds:[2]

               mov   word ptr es:[9*4],offset int9       ;设置新的中断向量表
               mov   es:[9*4+2],cs

       ;应用层：
               mov   ax,0b800h
               mov   es ,ax                              ;准备显存段地址

               mov   ah,'a'                              ;待显示内容
               sti                                       ;处理中断
       s:      
               mov   es:[160*12+40*2],ah                 ;12行40列
               call  delay
               inc   ah
               cmp   ah,'z'
               jna   s                                   ;如果不高于'z'

               mov   ax,0
               mov   es,ax

       ;将中断向量表中int 9中断例程的入口地址恢复为原来的地址
       ;否则后续程序将无法使用键盘
               push  ds:[0]
               pop   es:[9*4]
               push  ds:[2]
               pop   es:[9*4 +2]

               mov   ax,4c00h
               int   21h                                 ;返回系统
       ;}

       delay:  
       ;{
               push  ax                                  ;循环1000 0000h次
               push  dx                                  ;寄存器值入栈

               mov   dx,3h                               ;高位
               mov   ax,0                                ;低位
       s1:     sub   ax,1
               sbb   dx,0
               cmp   ax,0
               jne   s1                                  ;ax没减少到0就跳到si反复减ax,
               cmp   dx,0
               jne   s1
               cmp   dx,0                                ;dx不等于0，也反复到si减dx,每当ax从零减时候dx减少1
               jne   s1

               pop   dx
               pop   ax
               ret
       ;}
       int9:   
       ;{
               push  ax                                  ;用到的寄存器值入栈
               push  bx
               push  es

               in    al,60h

               pushf                                     ;标志寄存器入栈

       ;设置IF，TF等于0可以不加：
       ;  pushf
       ;  pop   bx                                  ;标志寄存器的值搞到bx中
       ;  and   bh,11111100b                        ;IF,TF标志在第8，9位，给这两位清零
       ;  push  bx
       ;  popf                                      ;修改完了再放回标志位寄存器

               call  dword ptr ds:[0]                    ;调用原int9中断程序

               cmp   al,1
               jne   int9ret                             ;如果不是0退出

               mov   ax,0b800h
               mov   es,ax
               inc   byte ptr es:[160*12+40*2+1]         ;是0改变颜色


       int9ret:pop   es
               pop   bx
               pop   ax
               iret

       ;}
code ends
end main