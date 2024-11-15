> CH14.LIB
```
; MESSAGE POINTED TO BY STACK OUT TO CONSOLE
SPMSG:  XTHL                    ; GET "RETURN ADRESS" TO hL
        XRA     A               ; CLEAR FLAGS AND ACCUMULATOR
        ADD     M               ; GET ONE MESSAGE CHARACTER
        INA     H               ; POINT TO NEXT
        XTHL                    ; RESTORE STACK FOR
        RZ                      ; RETURN IF DONE
        CALL    CO              ; ELSE DISPLAY CHARACTER
        JMP     SPMSG           ; AND DO ANOTHER
; GET YES OR NO FROM CONSOLE
GETYN:  CALL    SPMSG           ; PROMPT FOR INPUT
        DB      ' (Y/N)?: ',0
        CALL    CIMSG           ; GET INPUT LANE
        CALL    CCRLF           ; ECHO CARRIAGE RETURN
        LDA     INBUF+2         ; FIRST CHARACTER ONLY
        ANI     01011111B       ; CONVERT LOWER CASE TO UPPER
        CPI     'Y'             ; RETURN WITH ZERO = YES
        RZ
        CPI     'N'             ; NON-ZERO = NO
        JNZ     GETYN           ; ELSE TRY AGAIN
        CPI     0               ; RESET ZERO FLAG
        RET                     ; AND ALL DONE
```