TITLE	CLASS AVERAGE
.MODEL	SMALL
.STACK	100H
.DATA
FIVE	DW	5
SCORES	DW	67, 45, 98, 33	; Mary Allen
	DW	70, 56, 87, 44	; Scott Baylis
	DW	82, 72, 89, 40	; George Frank
	DW	80, 67, 95, 50	; Beth Harris
	DW	78, 76, 92, 60	; Sam Wong
AVG	DW	5 DUP (0)
.CODE	
MAIN	PROC
	MOV	AX, @DATA	; initialize DS
	MOV	DS, AX
; j = 4
	MOV	SI, 6		; col index, initially col4
REPEAT:
	MOV	CX, 5		; no. of rows
	XOR	BX, BX		; row index, initially 0
	XOR	AX, AX		; col_sum, initially 0
; sum scores in column j
FOR:
	ADD	AX, SCORES[BX + SI]  ; col_sum = col_sum + score
	ADD	BX, 8		; index next row
	LOOP	FOR		; keep adding scores
; endfor
; compute average in column j
	XOR	DX, DX		; clear high part of divnd
	DIV	FIVE		; AX = average
	MOV	AVG[SI], AX	; store in array
    mov ah,2
    MOV DL,AVG[SI]
    INT 21h
	SUB	SI, 2		; go to next column
	;until j = 0
	JNL	REPEAT		; unless SI < 0
; dos exit
	MOV	AH, 4CH
	INT	21H
MAIN	ENDP
	END	MAIN