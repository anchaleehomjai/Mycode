TITLE	Lab03 PROGRAM
.MODEL	SMALL
.STACK	100H
.DATA
Space DB ' ','$'
.CODE
MAIN	PROC
; intialize DS
	MOV	AX, @DATA	; get data segment
	MOV	DS, AX		; intialize DS

    MOV BX,80H
    MOV CX,0
TOP:
;check 10 char
    CMP CX,10
    JE NEWLINE
    INC CX
;print char
    MOV AH,2
    MOV DL,BX
    INT 21H
    INC BX 
;space 
    LEA DX,Space
    MOV AH,9
    INT 21H

;check value IN BL
    CMP BX,0FFH
    JE END_ 

    JMP TOP

NEWLINE:
    MOV	AH, 2		; display character function
	MOV	DL, 0DH		; carriage return
	INT	21H		; execute carriage return
	MOV	DL, 0AH		; line feed
	INT	21H		; execute line feed
    MOV CL,0
    JMP TOP
END_:
MOV	AH, 4CH		; DOS exit function
INT	21H		; exit to DOS
MAIN	ENDP
    END MAIN
