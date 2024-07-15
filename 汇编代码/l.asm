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

            mov  ax,data          ;z中转
            mov  ds,ax            ;把data数据段放到ds中
            mov  bx,0             ;初始化大偏移
            mov  si,0             ;初始化小偏移
            mov  cx,4             ;设置外层循环次数量

      s:    mov  dx,cx            ;保存外层循环数量
      
            mov  cx,3             ;设置内层循环数量
      s1:   
            mov  al,[bx][si]      ;加载到al中进行操作
            and  al,0dfh          ;字母小写变大写
            mov  [bx+si],al       ;操作完的数再放回原内存中
            inc  si               ;小偏移自增
            loop s1               ;执行内层循环

            mov  si,0             ;小偏移清零，以准备下一次外层循环
            mov  cx,dx            ;恢复外层循环时的循环数
            add  bx,16            ;大偏移自增
            loop s                ;执行内层循环

            mov  ax,4c00H         ;结束语句
            int  21h
code ends
end start