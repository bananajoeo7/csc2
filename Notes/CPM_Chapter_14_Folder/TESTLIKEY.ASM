; ASCII CHARACTERS
CR              EQU     0DH             ; CARRIAGE RETURN
LF              EQU     0AH             ; LINE FEED
SQT             EQU     27H             ; SINGLE QUOTE

; CP/M BDOS FUNCTIONS
RCONF           EQU     1               ; READ CON: INTO A
WCONF           EQU     2               ; WRITE A TO CON:
RBUFF           EQU     10              ; READ A CONSOLE LINE

; CP/M ADDRESSES
RBOOT           EQU     0               ; RE-BOOT CP/M SYSTEM
BDOS            EQU     5               ; SYSTEM CALL ENTRY
TPA             EQU     100H            ; TRANSIENT PROGRAM AREA

                ORG     TPA             ; ASSEMBLE PROGRAM FOR TPA

; PROGRAM
START           LXI     SP,STAK         ; SET UP USER'S STACK
START1:         CALL    TWOCR           ; DOUBLE SPACE LINES
                CALL    SPMSG           ; DISPLAY SIGN-ON MESSAGE
                DB      'WELCOME TO TROSTIN',SQT,'S LIKEY PROGRAM',CR,LF,0
START2:         CALL    TWOCR           ; DOUBLE SPACE LINES
                CALL    GETTHING        ; THING PROMPT
                DB      'WOW, YOU MUST REALLY NOT LIKEY ',0
                LXI     H,INBUF+2       ; POINT TO THING
                CALL    COMSG           ; ECHO THING
                CALL    SPMSG
                DB      ' THATS TOO SAD DUDE.',0
                JMP     START2
START3:         CALL    SPMSG
                DB      'WOW, YOU MUST REALLY LIKEY ',0
                LXI     H,INBUF+2       ; POINT TO THING
                CALL    COMSG           ; ECHO THING
                CALL    SPMSG
                DB      ' THATS PRETTY COOL DUDE.',0
                JMP     START2

; CONSOLE CHARACTER INTO REGISTER A MASKED TO 7 BITS
CI:             PUSH    B               ; SAVE REGISTERS
                PUSH    D
                PUSH    H        
                MVI     C,RCONF         ; READ FUNCTION
                CALL    BDOS
                ANI     7FH             ; MASK TO 7 BITS
                POP     H               ; RESTORE REGISTERS
                POP     D
                POP     B
                RET

; CHARACTER IN REGISTER A OUTPUT TO CONSOLE
CO:             PUSH    B               ; SAVE REGISTERS
                PUSH    D
                PUSH    H
                MVI     C,WCONF         ; SELECT FUNCTION
                MOV     E,A             ; CHARACTER TO E
                CALL    BDOS            ; OUTPUT BY CP/M
                POP     H               ; RESTORE REGISTERS
                POP     D
                POP     B
                RET

; PRINT TWO LINES BY CALLING CCRLF TWICE
TWOCR:          CALL    CCRLF

; CARRIAGE RETURN, LINE FEED TO CONSOLE
CCRLF:          MVI     A,CR
                CALL    CO
                MVI     A,LF
                JMP     CO

; MESSAGE POINTED TO BY HL OUT TO CONSOLE
COMSG:          MOV     A,M             ; GET A CHARACTER
                ORA     A               ; ZERO IS THE TERMINATOR
                RZ                      ; RETURN ON ZERO
                CALL    CO              ; ELSE OUTPUT THE CHARACTER
                INX     H               ; POINT TO THE NEXT ONE
                JMP     COMSG           ; AND CONTINUE

; INPUT CONSOLE MESSAGE INTO BUFFER
CIMSG:          PUSH    B               ; SAVE REGISTERS
                PUSH    D
                PUSH    H
                LXI     H,INBUF+1       ; ZERO CHARACTER COUNTER
                MVI     M,0
                DCX     H               ; SET MAXIMUM LINE LENGTH
                MVI     M,80
                XCHG                    ; INBUF POINTER TO DE REGISTER
                MVI     C,RBUFF         ; SET UP READ BUFFER FUNCTION
                CALL    BDOS            ; INPUT A LINE
                LXI     H,INBUF+1       ; GET CHARACTER COUNTER
                MOV     E,M             ; INTO LSB OF DE REGISTER PAIR
                MVI     D,0             ; ZERO MSB
                DAD     D               ; ADD LENGTH TO START
                INX     H               ; PLUS ONE POINTS TO END
                MVI     M,0             ; INSERT TERMINATOR AT END
                POP     H               ; RESTORE ALL REGISTERS
                POP     D
                POP     B
                RET

; MESSAGE POINTED TO BY STACK OUT TO CONSOLE 
SPMSG:          XTHL                    ; GET "RETURN ADDRESS" TO HL
                XRA     A               ; CLEAR FLAGS AND ACCUMULATOR
                ADD     M               ; GET ONE MESSAGE CHARACTER
                INX     H               ; POINT TO NEXT
                XTHL                    ; RESTORE STACK FOR
                RZ                      ; RETURN IF DONE
                CALL    CO              ; ELSE DISPLAY CHARACTER
                JMP     SPMSG           ; AND DO ANOTHER

GETYN:          CALL    SPMSG           ; PROMPT FOR INPUT
                DB      ' (Y/N)?: ',0
                CALL    CIMSG           ; GET INPUT LINE
                CALL    CCRLF           ; ECHO CARRIAGE RETURN
                LDA     INBUF+2         ; FIRST CHARACTER ONLY
                ANI     01011111B       ; CONVERT LOWER CASE TO UPPER
                CPI     'Y'             ; RETURN WITH ZERO = YES
                RZ
                CPI     'N'             ; NON-ZERO = NO
                JNZ     GETYN           ; ELSE TRY AGAIN
                CPI     0               ; RESET ZERO FLAG
                RET                     ; AND ALL DONE

; GET THING FROM CONSOLE
GETTHING:       CALL    SPMSG           ; DISPLAY PROMPT
                DB      'Name a thing: ', 0
                CALL    CIMSG           ; GET INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                CALL    SPMSG
                DB      'WOW, ',0
                CALL    COMSG           ; ECHO THING
                CALL    SPMSG
                DB      ', NOW THATS A THING.',0
                RET                     ; AND ALL DONE

; ASK IF USER LIKEY THING
LIKEYTHING:     CALL    TWOCR           ; ADD TWO LINES
                CALL    SPMSG           ; PROMPT USER IF LIKEY
                DB      'DO YOU LIKEY ',0
                LXI     H,INBUF+2       ; POINT TO THING
                CALL    COMSG           ; ECHO USER'S THING
                CALL    GETYN           ; GET RESULT IF LIKEY
                JNZ     START3          ; GOT A "NO"
                RET                     ; GOT A "YES"

INBUF:          DS      83              ; LINE INPUT BUFFER

; SET UP STACK SPACE
                DS      64              ; 40H LOCATIONS
STAK:           DB      0               ; TOP OF STACK

                END
