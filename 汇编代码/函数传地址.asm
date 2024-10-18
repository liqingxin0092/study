ASSUME CS:code

data segment
          db 'conversation'
data ends

code segment
     main:mov  ax,data
          mov  ds,ax
          mov  si,0

          mov  cx,12
          call func
          


          mov  ax,4c00h                    ;结束语句
          int  21h

     func:and  byte ptr [si],11011111b
          inc  si
          loop func
          ret
code ends
end main