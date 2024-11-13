# CP/M Chapter 14 Notes: Tricky Techniques
## TWOCR:, a one-line subroutine:
You should display console mesagges, especially error and warning messages, should be displayed with blank lines above and below them. \

You could call "CCRLF:" twice
in a row before and after displaying such messages. But it is easier to add one line of code to CPMIO to implement a double line feed.

Immediately above CCRLF: in your CPMIO.ASM file, add
the line: \
```TWOCR: CALL CCRLF``` \
and now you can call TWOCR: instead of CCRLF twice

## SPMSG: displays in-line messages
Similarly to a newer program language you can essentially "print" messages. \
You can do this by using SPMSG, all you do is write: \
``` 
CALL SPMSG
DB 'Message text for the console', 0
```

## GETYN Subroutine: Operator Interrogation

GETYN is a subroutine designed to prompt the operator for a yes or no response.

- <b/>Prompt Displayed</b>: Displays the prompt `(YIN)?` on the screen and waits for the operator’s input.
- <b/>Line Editing</b>: Allows the operator to edit the response line and provides an option to abort the program with an immediate `CTRL-C`. If `CTRL-C` is pressed, the program exits and returns to CP/M.

### Valid Responses

- <b/>Accepted Responses</b>: The first character of the input must be:
  - `"Y"` or `"y"` for yes
  - `"N"` or `"n"` for no
- <b/>Input Flexibility</b>: Only the first character is examined, allowing responses such as:
  - `"yep"` or `"YEAH!"` for yes
  - `"nope"` for no
  - A simple `"y"` or `"n"` with a carriage return (CR) to submit the answer.
  
- <b/>Invalid Input Handling</b>: If an invalid character is entered (anything other than `y`, `n`, or `CTRL-C`), the prompt will reappear for another attempt.

### Return Behavior

- <b/>Zero Flag Usage</b>:
  - If the answer is yes, GETYN returns with the zero flag set.
  - If the answer is no, GETYN returns with the zero flag unset.

### Usage in Programs

1. <b/>Conditional Jump</b>: A program can call <b/>GETYN</b> and use a conditional jump based on the zero flag to determine the action:
   - Jump on zero (yes) or not zero (no).
   
2. <b/>Interaction with SPMSG</b>:
   - Typically, a program uses <b/>SPMSG</b> to ask a question, followed by <b>GETYN<b> to handle the yes/no response.


#### Refrence the LIB files to see examples.