ASSUME CS:code, DS:data, SS:stacks

data segment
           db "Beginners's All-purpose Symbolic Instruction Code.",0
data ends

stacks segment
             db 128 dup(0)
stacks ends

code segment

      main: 
      ;{
            mov  ax,data
            mov  ds,ax
            mov  si,0                      ;初始化数据指针

            call trans

            mov  ax,4c00h                  ;结束语
            int  21h
      ;}

      trans:
      ;{
            push cx                        ;寄存器值入栈

            mov  ch ,0                     ;检测数据是否为0
      top:  mov  cl,ds:[si]
            jcxz ok

            cmp  byte ptr ds:[si],97       ;判断字母大小写
            jb   ok1                       ;如果小于97跳转

            cmp  byte ptr ds:[si],122
            ja   ok1                       ;如果大于122就跳转

            mov  al,ds:[si]                ;运行到这里说明是小写字母
            and  al,0dfh                   ;转化为大写
            mov  ds:[si],al

      ok1:  inc  si
            jmp  top


      ok:   
            pop  cx                        ;寄存器值出栈
            ret
      ;}
code ends
end main