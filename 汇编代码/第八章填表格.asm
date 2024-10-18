ASSUME CS:code 
data segment
           db '1975','1976','1977','1978','1979'          ;21年
           db '1980','1981','1982','1983','1984'
           db '1985','1986','1987','1988','1989'
           db '1990','1991','1992','1993','1994'
           db '1995'

           dd 16     ,22    ,382    ,1356   , 2390        ;21个总收入
           dd 8000   ,16000 ,24486  ,50065  ,97479
           dd 140417 ,197514,345980 ,590827 ,803530
           dd 1183000,184300,2759000,3753000,4649000
           dd 5937000

           dw 3    ,7    ,9     ,13    ,28                ;21个人数
           dw 38   ,130  ,220   ,476   ,778
           dw 1001 ,1442 ,2258  ,2793  ,4037
           dw 5635 ,8226 ,11542 ,14430 ,15257
           dw 17800
data ends

table segment
            db 21 dup ('yaer summ ne ?? ')
table ends

code segment
      start:
            mov  ax,table                 ;初始化table位置
            mov  ds,ax

            mov  ax,data                  ;初始化data位置
            mov  es,ax


            mov  cx,21                    ;初始化外层循环
            mov  si,0
            mov  di,0
            mov  bx,0                     ;结构体数组下标，步长为10h
      s:                                  ; 循环开始
            mov  ax,es:0[si]              ;data 年份区的第si个年分
            mov  [bx][0],ax               ;转移到第bx结构体，年份区
            mov  ax,es:0[si+2]            ;data 年份区的第si个年分
            mov  [bx][2],ax               ;转移到第bx结构体，年份区

            mov  ax,es:84[si]
            mov  5[bx],ax
            mov  ax,es:84[si+2]
            mov  7[bx],ax

            mov  ax,es:168[di]
            mov  0ah[bx],ax

            add  bx,10h
            add  si,4
            add  di,2
            loop s                        ;循环结束


            mov  cx,21                    ;初始化外层循环
            mov  si,0
            mov  di,0
            mov  bx,0                     ;结构体数组下标，步长为10h
      s2:   
            mov  ax,es:84[si]             ;低位
            mov  dx,es:86[si]             ;高位
            div  word ptr es:168[di]
            mov  0Dh[bx],ax
            add  bx,10h
            add  si,4
            add  di,2
           
            loop s2


            mov  ax,4c00H                 ;结束语句
            int  21h
code ends
end start