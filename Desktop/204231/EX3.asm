title first and last capitals
.model small
.stack 100h
.DATA
promt db 'Type a line of text', 0dh. 0ah, '$'
nocap_msg db 0dh,0ah, 'No capitals = '
cap_msg db 0dh,0ah, 'First capital = '
first db '['
      db 'Last capital = '
last db '@$'

.code
main proc
; initalize ds
    mov ax, @DATA
    mov ds,ax
; display opening message
    mov ah, 9
    lea dx,promt
    int 21h
; read and proces a line of text
    mov ah,1
    int 21h
while_:
;while char is not a cariage return do
    cmp al,0dh
    je end_while
;if char is capital letter
    cmp al,'A'
    jnge end_if
    cmp AL,'Z'
    jnle end_if

    cmp al,first
    jnl check_last
;then first capital = char
    mov first,al
; end_if
check_last:
;if char follower last capital
    cmp al,last
    jng end_if
;then last capital = char
    mov last,al
;end_if
end_if:
;read a char 
    int 21h
    jmp while_
end_while:
;display resulst
    mov ah,9
;if no capital were type
    cmp first, '['
    jne caps 
; then
    lea dx,nocap_msg
    jmp display
caps:
    lea dx, cap_msg
display:
    int 21h
;end if 
; dos
    mov ah, 4ch
    int 21h
main endp
     end main