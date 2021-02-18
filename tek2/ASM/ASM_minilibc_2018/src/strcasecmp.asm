BITS 64

SECTION .text

GLOBAL strcasecmp:function

strcasecmp:
 XOR RAX, RAX            ; put RAX to 0

end_func:
 RET                     ; return RAX -> the len