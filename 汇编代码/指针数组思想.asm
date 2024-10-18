assume cs:code

code segment
    s1:   db   'Good,Better,Best,','$'
    s2:   db   'Never let it rest,','$'
    s3:   db   'Till good is better','$'
    s4:   db   'And better,best','$'
    s:    dw   offset s1,offset s2,offset s3,offset s4
    row:  db   2,4,6,8

    start:mov  ax,cs
          mov  ds,ax
          mov  bx,offset s                                ;存放每行指针
          mov  si,offset row                              ;存放行数

          mov  cx,4                                       ;循环4次
    ok:   mov  bh,0                                       ;第0页
          mov  dh,ds:[si]                                 ;行号
          mov  dl,0                                       ;列号
          mov  ah,2                                       ;选择10h中断的2号子程序，设置光标位置
          int  10h

          mov  dx,ds:[bx]                                 ;字符串指向
          mov  ah,9                                       ;选择21h中断的9号程序，在光标位置显示字符串
          int  21h

          inc  si
          add  bx,2
          loop ok

          mov  ax,4c00h                                   ;返回系统
          int  21h

code ends
end start