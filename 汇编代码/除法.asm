ASSUME CS:code, ss:stacks

stacks segment
             db 64 dup (0)
stacks ends


code segment
      main: 
      ;{
            mov  ax,stacks       ;初始化栈指针
            mov  ss,ax
            mov  sp,64

      ;计算1 000 000 / 10      (f4240h/0ah)
            mov  ax,4240h        ;被除数低位,L
            mov  dx,000fh        ;被除数高位,X
            mov  cx,0ah          ;除数,N
            call divdw

            mov  ax,4c00h        ;结束语
            int  21h
      ;}

      divdw:                     ;公式int(H/N)*65536+[rem(H/N)*65536+L]/N
      ;{
            push bp              ;cx入栈

            push ax              ;暂存低位
            mov  ax,dx
            mov  dx,0            ;准备被除数(用户数据高位)
            div  cx              ;H/N
      ;此时ax为最终结果的高位，dx为H/N余数
            push ax              ;保存结果(最终结果高位)

      ;按照公式余数作为高位(余数目前已经是高位)，l作为低位
            mov  bp,sp
            mov  ax, [bp+2]      ;获取用户低位数据
            div  cx
      ;此时ax为最终结果低位，dx为最终结果余数
            mov  cx,dx           ;cx存储最终结果余数
            pop  dx              ;dx存储最终结果高位
      ;                          ;ax存储最终结果低位

            add  sp,2            ;回归栈顶前指针
            pop  bp
            ret
      ;}

code ends
end main