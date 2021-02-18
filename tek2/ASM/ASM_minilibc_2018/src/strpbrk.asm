BITS 64

SECTION .text

GLOBAL strpbrk:function

strpbrk:
 XOR RBX, RBX
 XOR RCX, RCX
 XOR RAX, RAX
 CMP RDI, 0
 JE end_zero
 CMP RSI, 0
 JE end_zero
 CMP byte [RDI], 0
 JE end_zero
 CMP byte [RSI], 0
 JE end_zero

loop2:
 MOV BL, [RDI]
 MOV CL, [RSI + RAX]
 CMP CL, 0
 JE loop1
 CMP CL, BL
 JE end_good
 INC RAX
 JMP loop2

loop1:
 XOR RAX, RAX
 INC RDI
 CMP byte [RDI], 0
 JE end_zero
 JMP loop2

end_zero:
 XOR RAX, RAX
 RET

end_good:
 MOV RAX, RDI
 RET