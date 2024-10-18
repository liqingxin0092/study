assume cs:code ,Ss:stacks
;直接定址表
stacks segment
             db 64 dup(0)
stacks ends

code segment
      main:    
      ;{
               mov  ax,stacks
               mov  ss,ax
               mov  sp,64                       ;初始化栈指针

               mov  al,0ACh                     ;参数

               call showbyte

               mov  ax,4c00h
               int  21h
      ;}

      showbyte:
      ;{
               jmp  short show
      table1   db   "0123456789ABCDEF"          ;字符表

      show:    push cx
               push bx
               push es                          ;用到的寄存器值入栈

               mov  ah,al
               mov  cl,4
               shr  ah,cl                       ;ah存字节高位
               and  al,00001111b                ;al存字节低位

               mov  bl,ah
               mov  bh,0
               mov  ah,table1[bx]               ;ah替换为对应的字符

               mov  bx ,0b800h
               mov  es,bx
               mov  es:[160*12+40*2],ah         ;显示高位

               mov  bl,al
               mov  bh,0
               mov  al,table1[bx]               ;al替换为对应的字符

               mov  es :[160*12+40*2+2],al      ;显示低位

               pop  es                          ;用到的寄存器值出栈
               pop  bx
               pop  cx
               ret
      ;}
    
code ends
end main