assume cs:code

data segment
         db 'welcome to masm!',0
data ends

code segment
    start:    mov  ax,cs
              mov  ds,ax
              mov  si,offset   d7chstart                    ;准备待安装程序指针
          
              mov  ax,0
              mov  es,ax
              mov  di,200h                                  ;准备目的地指针

              mov  cx, offset d7chend - offset d7chstart
              cld
              rep  movsb                                    ;开始安装

              mov  ax,0
              mov  es,ax
              mov  word ptr es:[7ch*4],200h
              mov  word ptr es:[7ch*4+2],0                  ;设置中断向量表
            
    ;中断应用：
              mov  ax,0b800h
              mov  es,ax
              mov  di ,160*12                               ;准备显存指针

              mov  bx,offset s-offset se                    ;设置从se到s标号的转移
              mov  cx,80
    s:        mov  byte ptr es:[di],'!'
              add  di,2
              int  7ch                                      ;调用中断程序(相当于loop s)
    se:       nop

              mov  ax ,4c00h                                ;主程序结束语句
              int  21h

    d7chstart:push bp                                       ;用到的寄存器值入栈

              mov  bp,sp                                    ;不能直接操作sp
              dec  cx                                       ;cx自减
              jcxz ok                                       ;如果减到0就不跳转
              add  [bp+2], bx                               ;此时sp指向的是刚才入栈的bp，bp+2指向cs

    ok:       pop  bp                                       ; 用到的寄存器值出栈
              iret

    d7chend:  
              nop

code ends
end start