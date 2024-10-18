ASSUME CS:code

data segment
         db 'conversation',0
data ends

code segment
    start:   
    ;安装部分:
             mov  ax,CS
             mov  ds,ax
             mov  si,offset do7c                    ;准备待安装部分指针

             mov  ax,0
             mov  es,ax
             mov  di,200h                           ;准备目的地指针

             mov  cx,offset do7c_end-offset do7c    ;设置转移步数
             cld
             rep  movsb                             ;开始转移

             mov  ax,0
             mov  es ,ax
             mov  word ptr es:[7ch*4],200h
             mov  word ptr es:[7ch*4+2],0           ;设置中断向量表

    
    ;应用部分:
             mov  ax,data
             mov  ds,ax
             mov  si,0                              ;准备数据指针

             mov  ax,0b800h
             mov  es,ax
             mov  di,120*16                         ;准备显存地址

    s:       cmp  byte ptr [si],0
             je   ok                                ;是0跳出

             mov  al,ds:[si]
             mov  es:[di],al                        ;数据到显存
             mov  byte ptr es:1[di],3
             inc  si
             add  di ,2
             mov  bx ,offset s-offset ok            ;计算步数到bx里
             int  7ch

    ok:      mov  ax,4c00h
             int  21h

    ;待安装程序:
    do7c:    
             push bp
             mov  bp,sp                             ;sp不能直接用，得先把他的值放到bp里
             add  [bp+2],bx                         ;原来栈中ip的位置加上bx也就是偏移量

             pop  bp
             iret                                   ;其中隐含的pop ip过程修改了IP

    do7c_end:
             nop
code ends
end start