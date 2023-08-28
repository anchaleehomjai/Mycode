TITLE	ECHO PROGRAM
.MODEL	SMALL
.STACK	100H
.DATA
CHAR1 DB ?, '$'
CHAR2 DB ?, '$'
.CODE
MAIN	PROC
; display prompt
	MOV	AH, 2		; display character function
	MOV	DL, '?'		; character is '?'
	INT	21H		; display it
; input a character
	MOV	AH, 1		; read character function
	INT	21H		; character in AL
	MOV	CHAR1, AL		; save it in BL
; input a character
	MOV	AH, 1		; read character function
	INT	21H		; character in AL
	MOV	CHAR2, AL		; save it in BL

; go to a new line
	MOV	AH, 2		; display character function
	MOV	DL, 0DH		; carriage return
	INT	21H		; execute carriage return
	MOV	DL, 0AH		; line feed
	INT	21H		; execute line feed
    
    MOV CH,CHAR1
    MOV BL,CHAR2
;if char1 < char2
    CMP CH,BL
    JNL DisplayChar2Char1
;then 
; display character
    MOV AH, 2
	MOV	DL, char1; retrieve character
	INT	21H		; and display it
; display character
    MOV AH, 2
	MOV	DL, CHAR2	; retrieve character
	INT	21H		; and display it
    JMP ENDIF_

DisplayChar2Char1:
; display character
    MOV AH, 2
	MOV	DL, char2	; retrieve character
	INT	21H		; and display it
; display character
    MOV AH, 2
	MOV	DL, char1	; retrieve character
	INT	21H		; and display it

ENDIF_:

; return to DOS
	MOV	AH, 4CH		; DOS exit function
	INT	21H		; exit to DOS
MAIN	ENDP
	END MAIN