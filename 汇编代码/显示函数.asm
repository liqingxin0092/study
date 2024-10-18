ASSUME CS:code, ss:stacks

stacks segment
             db 64 dup (0)
stacks ends

data segment
           db 'nihao',0
data ends

code segment
      main:    
               mov  dh,24            ;行号
               mov  dl,32            ;列号
               mov  cl,4             ;颜色

               mov  ax,data          ;初始化用户数据指针,也是函数处理数据指针
               mov  ds,ax
               mov  si,0

               mov  ax,stacks        ;初始化栈指针
               mov  ss,ax
               mov  sp,64

               call show_str

               mov  ax,4c00h
               int  21h

      show_str:
      ;{
               push ax               ;用到的寄存器入栈
               push cx
               push si
               push di
               push ds
               push es
               push bx
      ;参数转存：
               mov  bh,cl            ;因为寄存器不够用了
      ;初始化显存指针：
               mov  ax,0b800h        ;显存段地址
               mov  es,ax
               mov  di,0             ;显存指针
               
      ;计算显存指针:
      ;计算行偏移:
               sub  dh,1             ;公式：(行号-1)*A0
               mov  al,dh
               mov  ah,0
               mov  bl,0a0h
               mul  bl
               add  di,ax            ;显存指针加上行偏移

      ;计算列偏移：
               sub  dl,1             ;公式：(列号-1)*2
               mov  ah,0
               mov  al,dl
               mov  bl,2
               mul  bl
               add  di,ax

      ;基础处理单元：
      while_:  mov  ch,0
               mov  cl,ds:[si]       ;用户数据导入cx,判断是否为0
               jcxz return           ;如果是0就退出函数
      ;如果不是0，就在ax中进行数据处理：
               mov  al,ds:[si]
               mov  ah,bh            ;设置字体
               inc  si               ;用户数据指针自增
               
      ;写入显存:
               mov  es:[di] ,ax
               add  di,2             ;显存地址自增
               jmp  while_           ;重复

      return:  pop  es               ;用到的寄存器出栈
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