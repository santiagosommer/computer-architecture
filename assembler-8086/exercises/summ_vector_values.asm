; Implement a routine that adds, in ascending order, the elements of a vector 
; containing 1024 words, located starting at the label VECTOR, 
; and returns in AX the position of the addend where a carry occurs.
; If no carry is produced after completing all additions, 
; the routine should return the value 0.
; Assume that when the routine is invoked, VECTOR is pointed to by ES:BX.

; High level code
;
; unsigned short VECTOR[1024];
; unsigned int summ = 0;
; 
; for (unsigned short i = 0; i < 1024; i++) {
;   summ += VECTOR[i];
;   if (CARRY) {
;     return i;
;   }
; }
; return 0

.data

.code
 ; Init
 XOR AX, AX; summ = 0
 MOV CX, 1
 XOR SI, SI; i = 0

 ; Loop
 loop:
  CMP SI, 2048; i < 1024
  JE finishLoop
  MOV ES:[BX+SI], CX
  ADD AX, ES:[BX+SI]; summ += VECTOR[i]
  JC carry
  ADD SI, 2; i++
  JMP loop

 finishLoop:
 XOR AX, AX

 carry:
 SHR SI, 1 ; Divide SI/2 to return correct index 
 MOV AX, SI
 
.ports

.interrupts