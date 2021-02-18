BITS 64

SECTION .text

GLOBAL memset:function

memset:
 XOR RAX, RAX
 CMP RDI, 0
 JE end_func
 CMP EDX, 0
 JE end_func

my_loop:
 MOV [RDI + RAX], SIL
 INC RAX
 CMP EAX, EDX
 JL my_loop

end_func:
 MOV RAX, RDI
 RET