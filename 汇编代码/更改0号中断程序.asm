ASSUME CS:code

code segment

    main:    
    ;{
             mov  ax,CS
             mov  ds,ax
             mov  si,offset do0                  ;设置待安装程序指针

             mov  ax,0
             mov  es,ax
             mov  di,200h                        ;设置目的地指针

             mov  cx,offset do0end-offset do0    ;设置转移长度
             cld                                 ;正向传送;std是逆向传送;改变df标志位,0递增,1递减
             rep  movsb                          ;以字节为单位传送

             mov  ax,0                           ;修改中断向量表
             mov  es,ax
             mov  word ptr es:[0*4],200h         ;低位存偏移
             mov  word ptr es:[0*4+2],0          ;高位存段地址

             mov  ax ,1000h
             mov  bh , 1
             div  bh


             mov  ax,4c00h                       ;结束语句
             int  21h
    ;}

    do0:                                         ;待安装程序
    ;{
             jmp  short do0start
             db   "over flow - liqingxin0092"    ;定义待显示数据

    do0start:mov  ax,CS
             mov  ds,ax
             mov  si,202h                        ;设置字符串指针

             mov  ax,0b800h
             mov  es,ax
             mov  di,12*16+36*2                  ;设置显存指针

             mov  cx,25                          ;字符串长度
    s:       mov  al,[si]                        ;由字符串到显存的转移
             mov  es:[di],al
             inc  si
             add  di ,2
             loop s

             mov  ax,4c00h                       ;中断程序结束的结束语句，返回系统
             int  21h
    do0end:  nop
    ;}
code ends
end main