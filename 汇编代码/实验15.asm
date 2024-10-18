ASSUME CS:code

stack segment
              db 128 dup(0)
stack ends

code segment
        main:   mov   ax,stack
                mov   ss ,ax
                mov   sp ,128                              ;准备栈指针

                push  CS
                pop   ds                                   ;cs存到ds里

                mov   ax,0
                mov   es,ax                                ;es给0

                mov   si,offset int9                       ;安装中断
                mov   di,204h
                mov   cx,offset int9end-offset int9
                cld
                rep   movsb                                ;ds:[si]转运到es:[di],程序代码安装到0:204h处

                push  es:[9*4]                             ;原int9入口地址保存到0:200h处
                pop   es:[200h]
                push  es:[9*4+2]
                pop   es:[202h]

                cli                                        ;IF=0不响应可屏蔽中断
                mov   word ptr es:[9*4],204h               ;把自定义中断程序的入口设置到int9中断向量表
                mov   word ptr es:[9*4+2],0
                sti                                        ;IF=1响应可屏蔽中断

                mov   ax,4c00h                             ;退出到系统
                int   21h

        int9:   push  ax
                push  bx
                push  cx
                push  es

                in    al,60h                               ;读取键盘扫描码

                pushf                                      ;模拟int组成部分
                call  dword ptr cs:[200h]                  ;当中断例程执行时,cs=0,因为int9中断程序放在了0:204处

                cmp   al,9eh
                jne   int9ret                              ;不是0结束

                mov   ax,0b800h
                mov   es,ax
                mov   bx,0

                mov   cx,2000                              ;改变背景颜色
        s:      mov   byte ptr es:[bx],'A'
                add   bx,2
                loop  s

        int9ret:pop   es
                pop   cx
                pop   bx
                pop   ax
                iret

        int9end:nop
code ends
end main
