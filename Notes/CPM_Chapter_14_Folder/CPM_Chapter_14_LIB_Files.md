> CH14.LIB
```
; MESSAGE POINTED TO BY STACK OUT TO CONSOLE
SPMSG:  XTHL                    ; GET "RETURN ADRESS" TO HL
        XRA     A           
        ADD     M
        INA     H
        XTHL    
        RZ
        CALL    CO
        JMP     SPMSG
; GET YES OR NO FROM CONSOLE
GETYN:  CALL    SPMSG
        DB      ' (YIN)?: ',0
        CALL    CIMSG
        CALL    CCRLF
        LDA     INBUF+2
        ANI     01011111B
        CPI     'Y'
        RZ
        CPI     'N'
        JNZ     GETYN
        CPI     0
        RET
```