assume cs:code,ds:data

data segment
           db "00/00/00 00:00:00"
data ends

stacks segment
             db 64 dup(0)
stacks ends

code segment

      main:  
             mov  ax,stacks
             mov  ss,ax
             mov  sp,64                                 ;初始化栈指针

             mov  ax,data
             mov  ds,ax
             mov  si,0                                  ;初始化数据指针

      while4:
             mov  cx ,3                                 ;执行3次循环,读取年月日
             mov  bl,9
             mov  si ,0
             mov  bl,9
      while1:
             push cx                                    ;暂存循环次数

             mov  al,bl
             dec  bl                                    ;bl放入al中待操作，bl自减

             out  70h ,al                               ;输出bl到70h中，表示要操作年/月/日
             in   al,71h                                ;读取年/月/日

             mov  ah,al
             mov  cl,4
             shr  ah,cl                                 ;获得十位
             and  al,00001111b                          ;获得个位

             add  ah,30h
             add  al,30h                                ;转化为字符

      ;写入数据区
             mov  ds:[si],ah
             mov  ds:[si+1],al
             add  si,3

             pop  cx
             loop while1
    
             mov  cx ,3                                 ;执行3次循环,读取年月日
             mov  bl,4
      while2:
             push cx                                    ;暂存循环次数

             mov  al,bl
             sub  bl,2                                  ;bl放入al中待操作，bl自减

             out  70h ,al                               ;输出bl到70h中，表示要操作年/月/日
             in   al,71h                                ;读取年/月/日

             mov  ah,al
             mov  cl,4
             shr  ah,cl                                 ;获得十位
             and  al,00001111b                          ;获得个位

             add  ah,30h
             add  al,30h                                ;转化为字符

      ;写入数据区
             mov  ds:[si],ah
             mov  ds:[si+1],al
             add  si,3

             pop  cx
             loop while2

             mov  cx,17
             mov  di ,0
             mov  si ,0
      while3:
             mov  bx,0b800h
             mov  es,bx

             mov  al,ds:[si]
             mov  byte ptr es:[160*12+40*2+di],al
             mov  byte ptr es:[160*12+40*2+di+1],3
             add  di,2
             inc  si
             loop while3
      
             jmp  while4

             mov  ax,4c00h
             int  21h
code ends
end main