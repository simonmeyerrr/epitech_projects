BITS 64

SECTION .text

GLOBAL strchr:function

strchr:
 CMP RDI, 0
 JE end_zero

my_loop:
 CMP byte [RDI], SIL
 JE end_good
 CMP byte [RDI], 0
 JE end_zero
 INC RDI
 JMP my_loop

end_good:
 MOV RAX, RDI
 RET

end_zero:
 XOR RAX, RAX
 RET