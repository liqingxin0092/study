assume cs:code ,Ss:stacks
;直接定址表
stacks segment
               db 64 dup(0)
stacks ends

code segment
        main:   
        ;{
                mov  ax,stacks
                mov  ss,ax
                mov  sp,64                                           ;初始化栈指针

                mov  ax,120                                          ;角度参数
                call showsin

                mov  ax,4c00h
                int  21h
        ;}

        showsin:
        ;{
                jmp  short show
        table1  dw   ag0,ag30,ag60,ag90,ag120 , ag150 , ag180        ;存下面的地址

        ag0     db   '0',0
        ag30    db   '0.5',0
        ag60    db   '0.886',0
        ag90    db   '1.00',0
        ag120   db   '0.886',0
        ag150   db   '0.5',0
        ag180   db   '0',0

        show:   push bx
                push es
                push si                                              ;用到的寄存器值入栈

                mov  bx,0b800h
                mov  es,bx                                           ;设置显存段地址

                mov  ah,0                                            ;角度到偏移的转化关系是:角度/30*2
                mov  bl,30
                div  bl
                mov  bl,al
                mov  bh,0
                add  bx,bx
                mov  bx,table1[bx]

                mov  si,160*12+40*2                                  ;设置显存
        shows:  mov  ah,cs:[bx]                                      ;bx存的是具体角度字符串的偏移,他们是在程序段里被定义的
                cmp  ah,0                                            ;ah里存的是具体数值
                je   showret                                         ;如果为0就退出
                mov  es:[si],ah                                      ;显示
                inc  bx
                add  si,2
                jmp  short shows

        showret:pop  si                                              ;用到的寄存器值出栈
                pop  es
                pop  bx
                ret
        ;}
    
code ends
end main