ASSUME CS:code ,ds:data
data segment
           db 'ibm             '
           db 'dec             '
           db 'dos             '
           db 'vax             '
           db '................'
data ends

code segment
      start:
            mov  ax,data
            mov  ds ,ax
            mov  bx ,0
            mov  si,0              ;初始化小偏移
            mov  cx,4              ;外层循环
      s:    
            mov  ds:[40h],cx       ;保存外层循环数

            mov  cx,3              ;内层循环
      s0:   
            mov  al ,[bx][si]
            and  al,0dfh           ;处理
            mov  [bx][si],al       ;还原回内存
            inc  si
            loop s0
            mov  si,0              ;初始化小偏移
            add  bx,16
            mov  cx,ds:[40h]
            loop s

         

            mov  ax,4c00H          ;结束语句
            int  21h
code ends
end start