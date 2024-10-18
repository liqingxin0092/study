assume cs:code ,Ss:stacks
;直接定址表
stacks segment
               db 64 dup(0)
stacks ends

;参数ah选择程序号: 0清屏幕，1选择前景色,al:0~7,2:选择背景色,al:0~7,3:往上翻一页
code segment
        main:     
        ;{
                  mov  ax,stacks
                  mov  ss,ax
                  mov  sp,64                             ;初始化栈指针

                  mov  ah,3                              ;参数：选择程序号
        ;   mov  al,3                                    ;选择颜色

                  call func

                  mov  ax,4c00h
                  int  21h
        ;}

        func:     
        ;{
                  jmp  set

        sub1:     push bx                                ;清屏
                  push cx
                  push es

                  mov  bx,0b800h
                  mov  es,bx
                  mov  bx,0

                  mov  cx,2000
        sub1s:    mov  byte ptr es:[bx],' '
                  add  bx,2
                  loop sub1s

                  pop  es
                  pop  cX
                  pop  bx
                  ret

        sub2:     push bx                                ;选前景色,后三位
                  push cx
                  push es

                  mov  bx,0b800h
                  mov  es ,bx
                  mov  bx,1

                  mov  cx,2000
        subs2:    and  byte ptr es:[bx],11110000b        ;颜色后三位清零
                  or   es :[bx],al                       ;al选颜色
                  add  bx,2
                  loop subs2

                  pop  es
                  pop  cx
                  pop  bx
                  ret

        sub3:     push bx
                  push cx
                  push es

                  mov  cl,4
                  shl  al,cl                             ;参数al左移四位

                  mov  bx,0b800h
                  mov  es ,bx
                  mov  bx,1
              
                  mov  cx,2000
        sub3s:    and  byte ptr es:[bx],10001111b        ;[4~6]位清零
                  or   es:[bx],al                        ;填参数
                  add  bx ,2
                  loop sub3s

                  pop  es
                  pop  cX
                  pop  bx
                  ret

        sub4:     push cx                                ;功能:向上翻一行
                  push si
                  push di
                  push es
                  push ds

                  mov  si ,0b800h
                  mov  es ,si
                  mov  ds,si
                  mov  si,160                            ;ds:si指向第n+1行
                  mov  di,0                              ;es:di指向第n行
                  cld                                    ;正向转运,si,di递增

                  mov  cx,24                             ;共复制24行外层循环
        sub4s:    push cx                                ;内层循环
                  mov  cx,160                            ;每行160个字节
                  rep  movsb                             ;转运
                  pop  cx
                  loop sub4s

                  mov  cx,80
                  mov  si ,0
        sub4si:   mov  byte ptr [160*24+si],' '          ;最后一行清空
                  add  si,2
                  loop sub4si

                  pop  ds
                  pop  es
                  pop  di
                  pop  si
                  pop  cx
                  ret

        setscreen:jmp  set

        table1:   dw   sub1,sub2,sub3,sub4

        set:      push bx                                ;ah选择程序号

                  CMP  ah,3                              ;判断功能号是否大于3
                  ja   sret

                  mov  bl,ah
                  mov  bh,0
                  add  bx,bx                             ;程序号->偏移

                  call word ptr table1[bx]               ;调用对应程序

        sret:     pop  bx
                  ret

        ;}
    
code ends
end main