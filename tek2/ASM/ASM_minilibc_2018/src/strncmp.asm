BITS 64

SECTION .text

GLOBAL strncmp:function

strncmp:
 XOR RBX, RBX            ; put RBX to 0
 XOR RCX, RCX            ; put RCX to 0
 XOR RAX, RAX            ; put RAX to 0

 CMP RDI, 0              ; compare RDI (str1) to null
 JE end_zero             ; if equal -> end_zero

 CMP RSI, 0              ; compare RSI (str2) to null
 JE end_zero             ; if equal -> end_zero

 CMP EBP, 0              ; compare EBP (n) to 0
 JLE end_zero            ; if <= -> end_zero

my_loop:
 MOV BL, [RDI + RAX]     ; BL = RDI[RAX] <=> a = str1[i]
 MOV CL, [RSI + RAX]     ; CL = RSI[RAX] <=> b = str2[i]

 CMP BL, 0               ; compare BL (str1[i]) to '\0'
 JE end_calcul           ; if equal -> end_calcul

 CMP CL, 0               ; compare CL (str2[i]) to '\0'
 JE end_calcul           ; if equal -> end_calcul

 CMP BL, CL              ; compare BL (str1[i]) to CL (str2[i])
 JNE end_calcul          ; if not equal -> end_calcul

 CMP EAX, EBP            ; compare EAX (i) to EBP (n)
 JGE end_calcul          ; if >= -> end_calcul

 INC RAX                 ; increment RAX (RAX += 1)
 JMP my_loop             ; -> my_loop


end_calcul:
 XOR RAX, RAX            ; put RAX to 0
 SUB EBX, ECX            ; sub EBX (str1[i]) with ECX (str2[i])
 MOV EAX, EBX            ; put EAX to BL (str1[i] - str2[i])
 RET                     ; return EAX

end_zero:
 XOR RAX, RAX            ; put RAX to 0
 RET                     ; return RAX            ; return RAX -> the len