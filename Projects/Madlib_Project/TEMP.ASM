; NEW PROMPT SUBROUTINES
STARTNEWPROMPT: CALL    CCRLF           ; NEW LINE
                CALL    SPMSG           ; START NEW MESSAGE
                RET                     ; ALL DONE

PERNEWPROMPT:   CALL    STARTNEWPROMPT  ; NEW LINE AND START DISPLAY MESSAGE
                DB      'GIVE A PERSON: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

PLANEWPROMPT:   CALL    STARTNEWPROMPT  ; NEW LINE AND START DISPLAY MESSAGE
                DB      'GIVE A PLACE: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

NOUNEWPROMPT:   CALL    STARTNEWPROMPT  ; NEW LINE AND START DISPLAY MESSAGE
                DB      'GIVE A NOUN: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

ADJNEWPROMPT:   CALL    STARTNEWPROMPT  ; NEW LINE AND START DISPLAY MESSAGE
                DB      'GIVE A ADJETIVE: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

ADVNEWPROMPT:   CALL    STARTNEWPROMPT  ; NEW LINE AND START DISPLAY MESSAGE
                DB      'GIVE A ADVERB: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE