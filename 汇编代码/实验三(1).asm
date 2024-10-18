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
              mov  dh,10                                    ;行号
              mov  dl,11                                    ;列号
              mov  cl,2                                     ;颜色

              mov  ax,data
              mov  ds,ax
              mov  si,0                                     ;设置待显示数据指针

              int  7ch                                      ;调用中断程序

              mov  ax ,4c00h                                ;主程序结束语句
              int  21h

    d7chstart:push ax                                       ;用到的寄存器值入栈
              push es
              push di
              push bx
    
              mov  ax,0b800h
              mov  es,ax
              mov  di,0                                     ;初始化显存指针
            
    ;计算显存指针偏移：
    ;计算行偏移
              sub  dh,1                                     ;公式：(行号-1)*A0
              mov  ah,0
              mov  al,dh
              mov  bx,0a0h
              mul  bl
              add  di,ax                                    ;显存指针加上行偏移
            
    ;计算列偏移
              sub  dl,1                                     ;公式：(列号-1)*2
              add  dl,dl
              mov  dh,0
              add  di,dx                                    ;列偏移加到显存指针中

              mov  bx,cx                                    ;存颜色到别处
    while1:   mov  cx,ds:[si]
              jcxz ok                                       ;检测是否为零，是0结束
    ;否则：
              mov  al,ds:[si]
              mov  es:[di],al                               ;转运字符
              mov  es:1[di],bl                              ;转运颜色
            
              inc  si
              add  di ,2
              jmp  short while1


    ok:       pop  bx
              pop  di                                       ;寄存器值出栈
              pop  es
              pop  ax
              iret

    d7chend:  
              nop

code ends
end start