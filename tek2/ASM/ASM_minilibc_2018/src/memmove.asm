BITS 64

SECTION .text

GLOBAL memmove:function

memmove:
 CMP RDI, 0
 JE end_func
 CMP RSI, 0
 JE end_func
 CMP EDX, 0
 JE end_func
 XOR RAX, RAX
 XOR RBX, RBX

my_loop:
 MOV BL, [RSI + RAX]
 MOV [RDI + RAX], BL
 INC RAX
 CMP EAX, EDX
 JL my_loop

end_func:
 MOV RAX, RDI
 RET