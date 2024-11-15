> CPMIO.ASM
```
; CP/M I/O SUBROUTINES   30 JULY 82

; ASCII CHARACTERS
CR      EQU     0DH     ; CARRIAGE RETURN
LF      EQU     0AH     ; LINE FEED
CTRLZ   EQU     1AH     ; OPERATION INTERRUPT

; CP/M BDOS FUNCTIONS
RCONF   EQU     1       ; READ CON: INTO (A)
WCONF   EQU     2       ; WRITE (A) TO CON:

; CP/M ADDRESSES
RBOOT   EQU     0       ; RE-BOOT CP/M SYSTEM
BDOS    EQU     5       ; SYSTEM CALL ENTRY
TPA     EQU     100H    ; TRANSIENT PROGRAM AREA

        ORG     TPA     ; ASSEMBLE PROGRAM FOR TPA

START:  LXI     SP,STAK ; SET UP USER'S STACK
START1: CALL    CI      ; INPUT A CONSOLE CHARACTER
        CPI     CTRLZ   ; OPERATOR INTERRUPT?
        JZ      RBOOT   ; YES, RETURN TO CP/M
        CALL    CO      ; NO, ECHO IT AND
        JMP     START1  ;  LOOP

; CONSOLE CHARACTER INTO REGISTER A MASKED TO 7 BITS
CI:     PUSH    B       ; SAVE REGISTERS
        PUSH    D
        PUSH    H
        MVI     C,RCONF ; READ FUNCTION
        CALL    BDOS
        ANI     7FH     ; MASK TO 7 BITS
        POP     H       ; RESTORE REGISTERS
        POP     D
        POP     B
        RET

; CHARACTER IN REGISTER A OUTPUT TO CONSOLE
CO:     PUSH    B       ; SAVE REGISTERS
        PUSH    D
        PUSH    H
        MVI     C,WCONF ; SELECT FUNCTION
        MOV     E,A     ; CHARACTER TO E
        CALL    BDOS    ; OUTPUT BY CP/M
        POP     H       ; RESTORE REGISTERS
        POP     D
        POP     B
        RET

; SET UP A STACK SPACE
        DS      64      ; 40H LOCATIONS
STAK:   DB      0       ; TOP OF STACK

        END
```