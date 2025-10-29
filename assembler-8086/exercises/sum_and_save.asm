.data  ; Data segment

.code  ; Code segment

  ; Init registers with random values
  mov cx, 0x0001
  mov dx, 0x0002
  mov si, 0x0003
  mov di, 0x0004

  ; Init data segment
  mov ax, 0x0800
  mov ds, ax

  ; Receive two numbers
  mov ax, 0xffff
  mov bx, 0xffff
 
  ; Sum
  add ax, bx

  ; If (overflow)
  jc overflow
  jmp end

  overflow:
  ; Save data 
  push di
  mov di, 0x0100
  mov [di], ax
  add di, 2
  mov [di], bx
  add di, 2
  mov [di], cx
  add di, 2
  mov [di], dx
  add di, 2
  mov [di], si
  add di, 2
  pop ax
  mov [di], ax

  ; End
  end:

.ports ; Port definition

.interrupts ; Interrupts handlers