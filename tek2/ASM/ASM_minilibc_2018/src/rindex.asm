BITS 64

SECTION .text

GLOBAL rindex:function

rindex:
 XOR RAX, RAX
 CMP RDI, 0
 JE my_end

my_loop:
 CMP byte [RDI], SIL
 JNE my_loop_continue
 MOV RAX, RDI

my_loop_continue:
 CMP byte [RDI], 0
 JE my_end
 INC RDI
 JMP my_loop

my_end:
 RET