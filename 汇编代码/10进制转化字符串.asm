ASSUME CS:code, ss:stacks

stacks segment
             db 64 dup (0)
stacks ends

data segment
           db 10 dup(0)
data ends


code segment
      main:       
      ;{
                  mov  ax,stacks               ;初始化栈指针
                  mov  ss,ax
                  mov  sp,64

                  mov  ax,data                 ;初始化数据指针
                  mov  ds,ax
                  mov  si,0

                  mov  ax,15333                ;用户值

                  call dtoc

                  mov  dh,10
                  mov  dl,10
                  mov  cl,2
                  mov  si,0
                  call show_str

                  mov  ax,4c00h                ;结束语
                  int  21h
      ;}

      dtoc:       
      ;{
                  push bx                      ;寄存器值入栈

                  mov  bx,10                   ;置10作为除数
                  mov  di,0                    ;记录数量
                  
      while1:     mov  dx,0                    ;此时ax中存的是最初用户数据，或者ax多次/10的商
                  div  bx                      ;计算用户值/10  ,8位除法
                  inc  di                      ;每执行一次whiel1,就+1，用于判断栈中数据有多少位
                  push dx                      ;一位结果入栈(从个位起)
                  
                  mov  cx,ax                   ;看商是否为0
                  jcxz data_finish             ;是0说明数据处理结束
                  jmp  while1                  ;否则继续流程

      data_finish:
                  mov  cx,di                   ;栈中的数据处理

      s:          pop  ax
                  add  ax,30h
                  mov  ds:[si],al
                  inc  si
                  loop s
                  mov  byte ptr ds:[si],0

                  pop  bx                      ;寄存器值出栈`
                  ret
      ;}

      show_str:   
      ;{
                  push ax                      ;用到的寄存器入栈
                  push cx
                  push si
                  push di
                  push ds
                  push es
                  push bx
      ;参数转存：
                  mov  bh,cl                   ;因为寄存器不够用了
      ;初始化显存指针：
                  mov  ax,0b800h               ;显存段地址
                  mov  es,ax
                  mov  di,0                    ;显存指针
               
      ;计算显存指针:
      ;计算行偏移:
                  sub  dh,1                    ;公式：(行号-1)*A0
                  mov  al,dh
                  mov  ah,0
                  mov  bl,0a0h
                  mul  bl
                  add  di,ax                   ;显存指针加上行偏移

      ;计算列偏移：
                  sub  dl,1                    ;公式：(列号-1)*2
                  mov  ah,0
                  mov  al,dl
                  mov  bl,2
                  mul  bl
                  add  di,ax

      ;基础处理单元：
      while_:     mov  ch,0
                  mov  cl,ds:[si]              ;用户数据导入cx,判断是否为0
                  jcxz return                  ;如果是0就退出函数
      ;如果不是0，就在ax中进行数据处理：
                  mov  al,ds:[si]
                  mov  ah,bh                   ;设置字体
                  inc  si                      ;用户数据指针自增
               
      ;写入显存:
                  mov  es:[di] ,ax
                  add  di,2                    ;显存地址自增
                  jmp  while_                  ;重复

      return:     pop  es                      ;用到的寄存器出栈
                  pop  ds
                  pop  di
                  pop  si
                  pop  cx
                  pop  ax
                  pop  bx
                  ret
      ;}

code ends
end main