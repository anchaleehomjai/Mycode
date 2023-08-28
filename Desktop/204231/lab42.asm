TITLE	lab042 I/O
.MODEL	SMALL
.STACK	
.DATA
halfdallar DB ' half - dollar $'
quarter db ' quarter $'
dime db ' dime $'
nickel DB ' nickel $'
penny DB ' penny  $'
q dw 0
dim dw 0
n dw 0
p dw 0
.CODE
MAIN	PROC
; initalize ds
    mov ax, @DATA
    mov ds,ax
; input a number
	CALL	INDEC	; number in AX

    XOR DX, DX ;เป็นเวลา ไม่มีลบ จึงใช้ div
    MOV BX,50 ;เศษอยู่ใน DX จำนวนรอบอยู่ใน AX
    DIV BX

    CALL	OUTDEC ;เตรียมแสดงค่า
    mov q,DX ; ย้ายเศษเข้า ตัวแปร ก่อนเพราะมันจะงงกับตัว dx
    LEA dx,halfdallar
    mov ah,9
    int 21h
    mov ax,q ; ย้ายเศษกลับมาไว้ ax เพื่อจะเอาไปหารต่อ

    XOR DX, DX ; เคลียค่า
    MOV BX,25 ;เศษอยู่ใน DX จำนวนรอบอยู่ใน AX
    DIV BX 

    CALL	OUTDEC 
    mov dim,DX ; ย้ายเข้าตัวแปร
    LEA dx,quarter
    mov ah,9
    int 21h
    mov ax,dim

    XOR DX, DX ; เคลียค่า
    MOV BX, 10;เศษอยู่ใน DX จำนวนรอบอยู่ใน AX
    DIV BX 

    CALL	OUTDEC 
    mov n,DX ; ย้ายเข้าตัวแปร
    LEA dx,dime
    mov ah,9
    int 21h
    mov ax,n

    XOR DX, DX ; เคลียค่า
    MOV BX, 5;เศษอยู่ใน DX จำนวนรอบอยู่ใน AX
    DIV BX 

    CALL	OUTDEC 
    mov p,DX ; ย้ายเข้าตัวแปร
    LEA dx,nickel
    mov ah,9
    int 21h
    mov ax,p

    CALL	OUTDEC
    LEA DX,penny
    mov ah,9  ;แสดงค่า
    int 21h


; dos exit
	MOV	AH, 4CH
	INT	21H
MAIN	ENDP
INCLUDE	OUTDEC.ASM	; include OUTDEC
INCLUDE	INDEC.ASM	; include INDEC
	END	MAIN