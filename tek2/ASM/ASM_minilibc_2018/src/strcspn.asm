BITS 64

SECTION .text

GLOBAL strcspn:function

strcspn:
 XOR RAX, RAX            ; put RAX to 0

end_func:
 RET                     ; return RAX -> the len