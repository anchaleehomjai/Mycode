TITLE	lab041 I/O
.MODEL	SMALL
.STACK	
.DATA
hr DB ' hours $'
minnut db ' minutes $'
sec db ' seconds $'

min dw 0
hro dw 0
seccon dw 0

.CODE
MAIN	PROC
; initalize ds
    mov ax, @DATA
    mov ds,ax
; input a number
	CALL	INDEC	; number in AX

    XOR DX, DX ;เป็นเวลา ไม่มีลบ จึงใช้ div
    MOV BX,3600 ;เศษอยู่ใน DX จำนวนรอบอยู่ใน AX
    DIV BX

    CALL	OUTDEC ;เตรียมแสดงค่า
    mov min,DX ; ย้ายเศษเข้า ตัวแปร ก่อนเพราะมันจะงงกับตัว dx
    LEA dx,hr 
    mov ah,9
    int 21h
    mov ax,min  ; ย้ายเศษกลับมาไว้ ax เพื่อจะเอาไปหารต่อ

    XOR DX, DX ; เคลียค่า
    MOV BX,60  ;เศษอยู่ใน DX จำนวนรอบอยู่ใน AX
    DIV BX 

    CALL	OUTDEC 
    mov hro,DX ; ย้ายเข้าตัวแปร
    LEA dx,minnut
    mov ah,9
    int 21h
    mov ax,hro

    CALL	OUTDEC
    LEA DX,sec
    mov ah,9  ;แสดงค่า
    int 21h


; dos exit
	MOV	AH, 4CH
	INT	21H
MAIN	ENDP
INCLUDE	OUTDEC.ASM	; include OUTDEC
INCLUDE	INDEC.ASM	; include INDEC
	END	MAIN