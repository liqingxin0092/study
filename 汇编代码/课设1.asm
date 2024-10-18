ASSUME CS:code, ss:stacks

stacks segment
             db 64 dup (0)
stacks ends

data2 segment
            dw 16,22,382,1356,2390,8000,16000,24486,50065
            dd 97479,140417,197514,345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
data2 ends

data3 segment
            dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226,11542,14430,15257,17800
data3 ends

data segment
           db 128 dup(0)
data ends

code segment
      main:       
      ;{
                  mov  ax,stacks               ;初始化栈指针
                  mov  ss,ax
                  mov  sp,64

                  mov  ax,data                 ;初始化数据指针
                  mov  ds,ax
                  mov  si,0

                  mov  ax,1975                 ;用户值
                  mov  dh,2                    ;行数
                  mov  cx,21
      ssss:       mov  es,cx
                  call dtoc

                  mov  dl,9                    ;列数
                  mov  cl,3                    ;颜色
                  inc  ax
                  inc  dh                      ;行数加一
                  call show_str
                  mov  cx,es
                  loop ssss

                  mov  cx,9                    ;外层循环数
                  mov  di,0                    ;数据段下标归0
                  mov  dl,19                   ;列数
                  mov  dh,2                    ;行数
      xunhuan0:   push cx                      ;记录循环
                  
                  mov  ax,data2
                  mov  ds,ax                   ;初始化数据库区指针
                  mov  ax,ds:[di]              ;写入参数
                  
                  mov  bx,data
                  mov  ds,bx                   ;切换段地址
                  call dtoc
                  add  di,2
                  inc  dh                      ;行数
                  mov  cl,3                    ;颜色

                  mov  ax,data
                  mov  ds,ax
                  mov  si,0                    ;准备打印地址

                  call show_str
                  
                  pop  cx
                  loop xunhuan0


                  mov  cx ,12                  ;设置循环数
                  mov  di,18
      xunhuan:    push cx                      ;记录循环
                  push dx

                  mov  ax,data2
                  mov  ds,ax                   ;初始化数据库区指针
                                     
                  mov  ax,ds:[di]              ;写入参数
                  mov  dx,ds:[di+2]

                  mov  bx,data
                  mov  ds,bx                   ;切换段地址
                  add  di,4
                  call dtoc_dword

                  pop  dx
                  inc  dh                      ;行数
                  mov  cl,3                    ;颜色

                  mov  ax,data
                  mov  ds,ax
                  mov  si,0                    ;准备打印地址

                  call show_str

                  pop  cx                      ;恢复外循环
                  loop xunhuan


                  mov  cx,21                   ;外层循环数
                  mov  di,0                    ;数据段下标归0
                  mov  dl,30                   ;列数
                  mov  dh,2                    ;行数
      xunhuan2:   push cx                      ;记录循环
                  
                  mov  ax,data3
                  mov  ds,ax                   ;初始化数据库区指针
                  mov  ax,ds:[di]              ;写入参数
                  mov  bx,data
                  mov  ds,bx                   ;切换段地址
                  call dtoc
                  add  di,2
                  inc  dh                      ;行数
                  mov  cl,3                    ;颜色

                  mov  ax,data
                  mov  ds,ax
                  mov  si,0                    ;准备打印地址

                  call show_str

                  pop  cx
                  loop xunhuan2




                  mov  dh,2                    ;行数
                  mov  dl,40                   ;列数

                  mov  cx,9                    ;设置第一次循环数
                  mov  di,0                    ;设置公共下标
      xunhuan3:   push cx
                  push dx

                  mov  bx,data2                ;被除数段
                  mov  ds,bx

                  mov  ax,[di]                 ;低位
                  mov  dx,0                    ;高位

                  mov  bx ,data3               ;除数段
                  mov  ds,bx

                  mov  bx,[di]                 ;设置除数

                  div  bx

                  mov  bx ,data
                  mov  ds,bx                   ;结果放到这里面

                  call dtoc                    ;ax中存着商

                  mov  cl,3                    ;颜色
                  pop  dx
                  inc  dh

                  call show_str
                  add  di,2
                  pop  cx
                  loop xunhuan3

            
                  mov  cx,12
                  mov  bp ,18
      xuanhuan4:  push cx
                  push dx

                  mov  bx,data2                ;被除数段
                  mov  ds,bx

                  mov  ax,[di]                 ;低位
                  mov  dx,[di+2]               ;高位

                  mov  bx ,data3               ;除数段
                  mov  ds,bx

                  mov  cx,ds:[bp]              ;设置除数

                  call divdw

                  mov  bx ,data
                  mov  ds,bx                   ;结果放到这里面

                  call dtoc                    ;ax中存着商

                  mov  cl,3                    ;颜色
                  pop  dx
                  inc  dh

                  call show_str
                  add  di,4
                  add  bp,2

                  pop  cx
                  loop xuanhuan4

                  mov  ax,4c00h                ;结束语
                  int  21h
      ;}

      dtoc:       
      ;{
                  push cx
                  push dx
                  push bx                      ;寄存器值入栈
                  push ax
                  push si
                  push di

                  mov  bx,10                   ;置10作为除数
                  mov  di,0                    ;记录数量
                  
      while1:     mov  dx,0                    ;此时ax中存的是最初用户数据，或者ax多次/10的商
                  div  bx                      ;计算用户值/10  ,8位除法
                  inc  di                      ;每执行一次whiel1,就+1，用于判断栈中数据有多少位
                  push dx                      ;一位结果入栈(从个位起)
                  
                  mov  cx,ax                   ;看商是否为0
                  jcxz data_finish             ;是0说明数据处理结束
                  jmp  while1                  ;否则继续流程

      data_finish:
                  mov  cx,di                   ;栈中的数据处理

      s:          pop  ax
                  add  ax,30h
                  mov  ds:[si],al
                  inc  si
                  loop s
                  mov  byte ptr ds:[si],0

                  pop  di
                  pop  si                      ;寄存器值出栈
                  pop  ax
                  pop  bx
                  pop  dx
                  pop  cx
                  ret
      ;}

      show_str:   
      ;{
                  push dx
                  push ax                      ;用到的寄存器入栈
                  push cx
                  push si
                  push di
                  push ds
                  push es
                  push bx
      ;参数转存：
                  mov  bh,cl                   ;因为寄存器不够用了
      ;初始化显存指针：
                  mov  ax,0b800h               ;显存段地址
                  mov  es,ax
                  mov  di,0                    ;显存指针
               
      ;计算显存指针:
      ;计算行偏移:
                  sub  dh,1                    ;公式：(行号-1)*A0
                  mov  al,dh
                  mov  ah,0
                  mov  bl,0a0h
                  mul  bl
                  add  di,ax                   ;显存指针加上行偏移

      ;计算列偏移：
                  sub  dl,1                    ;公式：(列号-1)*2
                  mov  ah,0
                  mov  al,dl
                  mov  bl,2
                  mul  bl
                  add  di,ax

      ;基础处理单元：
      while_:     mov  ch,0
                  mov  cl,ds:[si]              ;用户数据导入cx,判断是否为0
                  jcxz return                  ;如果是0就退出函数
      ;如果不是0，就在ax中进行数据处理：
                  mov  al,ds:[si]
                  mov  ah,bh                   ;设置字体
                  inc  si                      ;用户数据指针自增
               
      ;写入显存:
                  mov  es:[di] ,ax
                  add  di,2                    ;显存地址自增
                  jmp  while_                  ;重复

      return:     pop  bx                      ;用到的寄存器出栈
                  pop  es
                  pop  ds
                  pop  di
                  pop  si
                  pop  cx
                  pop  ax
                  pop  dx
                  ret
      ;}

      dtoc_dword: 
      ;{
                  push ax
                  push di
                  push cx
                  push dx
                  push bx                      ;寄存器值入栈

                  mov  di,0                    ;记录数量

      while2:     mov  cx,10
                  call divdw                   ;除10
                  push cx                      ;余数入栈
                  inc  di                      ;记录数量

                  mov  cx,dx                   ;检查高位
                  jcxz dx_z
                  jmp  while2                  ;否则走while
 
      dx_z:       mov  cx,ax                   ;检查低位
                  jcxz ax_z                    ;如果是跳转到ax_z
                  jmp  while2                  ;    否则走到while

      ax_z:                                    ;跳到这里说明商彻底为0，可以进行数据处理\
                  mov  cx,di                   ;栈中的数据处理
      sss:        pop  ax                      ;弹到ax中处理
                  add  ax,30h
                  mov  ds:[si],al
                  inc  si
                  loop sss
                  mov  byte ptr ds:[si],0

                  pop  bx                      ;寄存器出栈
                  pop  dx
                  pop  cx
                  pop  di
                  pop  ax
                  ret
      
      ;}

      divdw:                                   ;公式int(H/N)*65536+[rem(H/N)*65536+L]/N
      ;{
            
                  
      
                  push bp                      ;cx入栈

                  push ax                      ;暂存低位
                  mov  ax,dx
                  mov  dx,0                    ;准备被除数(用户数据高位)
                  div  cx                      ;H/N
      ;此时ax为最终结果的高位，dx为H/N余数
                  push ax                      ;保存结果(最终结果高位)

      ;按照公式余数作为高位(余数目前已经是高位)，l作为低位
                  mov  bp,sp
                  mov  ax, [bp+2]              ;获取用户低位数据
                  div  cx
      ;此时ax为最终结果低位，dx为最终结果余数
                  mov  cx,dx                   ;cx存储最终结果余数
                  pop  dx                      ;dx存储最终结果高位
      ;                                        ;ax存储最终结果低位

                  add  sp,2                    ;回归栈顶前指针


                  pop  bp
                  
                  
                  ret
      ;}
code ends
end main