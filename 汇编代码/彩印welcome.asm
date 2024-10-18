ASSUME CS:code

data segment
           db 'welcome to masm!'      ;定义数据
data ends

code segment
      start:mov  ax,0B800h                 ;设置显存地址
            mov  ds,ax
            mov  bx ,520h
             
            mov  ax,data                   ;设置数据地址
            mov  es,ax
            mov  si,0

            mov  cx,16                     ;设置循环
      s:    mov  al,es:[si]                ;data中的数据搬运到显存中
            mov  [bx],al
            mov  byte ptr [bx+1],0ah       ;字体属性

            add  si,1
            add  bx,2

            loop s

            mov  bx ,5c0h
            mov  si,0
            mov  cx,16                     ;设置循环
      s1:   mov  al,es:[si]                ;data中的数据搬运到显存中
            mov  [bx],al
            mov  byte ptr [bx+1],071h      ;字体属性

            add  si,1
            add  bx,2

            loop s1


            mov  bx ,660h
            mov  si,0
            mov  cx,16                     ;设置循环
      s2:   mov  al,es:[si]                ;data中的数据搬运到显存中
            mov  [bx],al
            mov  byte ptr [bx+1],2ch       ;字体属性

            add  si,1
            add  bx,2

            loop s2

            mov  ax,4c00h                  ;结束语句
            int  21h
code ends
end start