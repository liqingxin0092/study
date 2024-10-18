ASSUME CS:code

data segment
          db 1,2,3,4,5,6,7,8
          dw 0,0,0,0,0,0,0,0
data ends

code segment
     main:mov  ax,data
          mov  ds,ax
          mov  si,0
          mov  di,8           ;data dd部分的偏移

          mov  cx,8
          mov  bh,0
     s:   mov  bl,[si]        ;放参数

          call func           ;调用
          mov  ds:[di],ax     ;接收参数
          
          inc  si
          add  di,2
          loop s
          mov  ax,4c00h       ;结束语句
          int  21h

     func:mov  ax,bx
          mul  bx
          mul  bx
          ret
code ends
end main