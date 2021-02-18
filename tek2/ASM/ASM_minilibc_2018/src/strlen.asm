BITS 64

SECTION .text

GLOBAL strlen:function

strlen:
 XOR RAX, RAX            ; put RAX to 0
 CMP RDI, 0              ; compare RDI to null
 JE end_func             ; go to the end of the function if null

my_loop:
 CMP byte [RDI + RAX], 0 ; compare the RAX th character to 0
 JE end_func             ; if prev cmp equal -> jump to end_func
 INC RAX                 ; increment RAX (RAX += 1)
 JMP my_loop             ; jump to my_loop

end_func:
 RET                     ; return RAX -> the len