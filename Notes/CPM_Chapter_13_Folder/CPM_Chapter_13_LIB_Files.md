> CH13.LIB
'''
; CARRIAGE RETURN, LINE FEED TO CONSOLE
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        JMP     CO
; MESSAGE POINTED TO BY HL OUT TO
COMSG:  MOV     A,M         ; GET A CHARACTER
        ORA     A           ; ZERO IS THE TERMINATOR
        RZ                  ; RETURN ON ZERO
        CALL    CO          ; ELSE OUTPUT THE CHARACTER
        INX     H           ; POINT TO THE NEXT ONE
        JMP     COMSG       ; AND CONTINUE

; INPUT CONSOLE MESSAGE INTO BUFFER
COMSG:  MOV     A,M         ; GET A CHARACTER
        ORA     A           ; ZERO IS THE TERMINATOR
        RZ                  ; RETURN ON ZERO
        CALL    CO          ; ELSE OUTPUT THE CHARACTER
        INX     H           ; POINT TO THE NEXT ONE
        JMP     COMSG       ; AND CONTINUE

; INPUT CONSOLE MESSAGE INTO BUFFER
CIMSG:  PUSH    B           ; SAVE REGISTERS
        PUSH    D
        PUSH    H
        LXI     H,INBUF+1   ; ZERO CHARACTER COUNTER
        MVI     M,O
        DCX     H           ; SET MAXIMUM LINE LENGTH
        MVI     M,80
        XCHG                ; INBUF POINTER TO DE REGISTERS
        MVI     C,RBUFF     ; SET UP PEAD BUFFER FUNCTION
        CALL    BDOS        ; INPUT A LINE
        LXI     H,INBUF+1   ; GET CHARACTER COUNTER
        MOV     E,M         ; INTO LSB OF DE REGISTER PAIR
        MVI     D,O         ; ZERO MSB
        DAD     D           ; ADD LENGTH TO START
        INX     H           ; PLUS ONE POINTS TO END
        MVI     M,O         ; INSERT TERMINATOR AT END
        POP     H           ; RESTORE ALL REGISTERS
        POP     D
        POP     B
        RET 

INBUF:  DS      83          ; LINE INPUT BUFFER 
'''

> TESTCH13.lib
'''
START1: CALL    CCRLF       ; START A NEW LINE
        LXI     H,SINON     ; WITH SIGN-ON MESSAGE
        CALL    COMSG
START2: CALL    CIMSG       ; GET A LINE OF INPUT
        CALL    CCRLF
        LXI     H,INBUF+2   ; POINT TO ITS TEXT
        CALL    COMSG       ; ECHO THE WHOLE LINE
        CALL    CCRLF       ; AND CR, LF
        JMP     START2      ; THEN DO ANOTHER
        
SINON:  DB                  ;'SIGN-ON MESSAGE' ,CR,LF,O 
'''