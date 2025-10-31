; Routine in 8086 assembly
; Given:
;   D1 - memory address in AX
;   D2 - memory address in BX
;   N  - number of bytes in DX
; Copies N consecutive bytes starting at D1 to D2
; Memory addresses are offsets relative to ES

; High level code
;
; unsigned char temp[i];
;
; for (int i=0; i<n; i++) {
;   temp[i] = D1[i]
; }
;
; for (int i=0; i<n; i++) {
;   D2[i] = temp[i]
; }

.data

.code
  ; addresses
  mov ax, 0x0100 ;d1
  mov bx, 0x0200 ;d2
  mov si, 0x0000
  mov bp, ax

  ; N
  mov dx, 50

  ; for body, stop condition (d1 == n)
  bodyFor:
   cmp si, dx
   jz postFor

   mov ES:[bp+si], si
   push ES:[bp+si]

   add si, 2
   jmp bodyFor

  ; for body
  postFor:
   sub si, 2
   cmp si, 0
   jz end

   pop cx
   mov ES:[bx+si], cx

   jmp postFor
  end:

.ports

.interrupts