TITLE    CLASS AVERAGE
.MODEL    SMALL
.STACK    100H
.DATA
FOUR    DW    4

CLASS    DB    'MARY ALLEN  ', 67, 45, 98, 33
        DB    'SCOTT BAYLIS', 70, 56, 87, 44
        DB    'GEORGE FRANK', 82, 72, 89, 40
        DB    'SAM WONG    ', 78, 76, 92, 60
AVG    DB    5 DUP (0)
.CODE    
MAIN    PROC
    MOV    AX, @DATA    ; initialize DS
    MOV    DS, AX
    MOV    SI, 0
; j = 5
REPEAT:
    XOR AX,AX
    XOR BX,BX
    MOV CX ,12
FOR_NAME:
    MOV DL,CLASS[SI]
    MOV AH,2
    INT 21h
    ADD SI,1
    LOOP FOR_NAME

    XOR AX,AX

    MOV    CX, 4        ; no. of col
; sum scores in col j
FOR:
    MOV DL,CLASS[SI]
    MOV DH,0
    ADD AX, DX ; 1row_sum = row_sum + score
    XOR DX,DX

    ADD   SI, 1        ; index next col
    LOOP  FOR        ; keep adding scores
    DIV   FOUR    ; BX = average
    CALL  OUTDEC 
    ; go to a new line
    MOV    AH, 2        ; display character function
    MOV    DL, 0DH        ; carriage return
    INT    21H        ; execute carriage return
    MOV    DL, 0AH        ; line feed
    INT    21H        ; execute line feed

    ;until j = 0
	;until j = 0
	CMP SI,63
	JL	REPEAT		; unless SI <= 63
    JMP END_        
END_:
; dos exit
    MOV    AH, 4CH
    INT    21H
    

MAIN    ENDP
INCLUDE    OUTDEC.ASM    ; include OUTDEC

    END    MAIN