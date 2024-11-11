# CP/M Chapter 11 Notes
note to self: 
- "ERA" is the command to erase files.
- Typing "e" exits the ed file.
- to enter a file you do "a:ed" followed by your file name.
- "v" enables the line numbers.
- "-v" disables the line numbers.
- Remeber to use "0a" at the beginning to load the file.
- Use "ki" to delete a line.

## Tools to Be Used
The CP/M manuals for ED, ASM, and DDT are important, but you don’t need to memorize everything right away. The tutorial introduces these tools, starting with a simplified subset of commands.

## Control Keys in ED
The editor ED requires the use of CTRL-Z (to exit input mode) and CTRL-I (to insert a tab) to navigate and format the program. It is recommended to use all uppercase letters when typing assembly language code for portability.

## Starting with ED
1. Load the program using the command `ED TEST.ASM`.
2. Enter the program in input mode using the `I` command. Each line of the assembly code is typed, and the cursor should return to the left column when input mode is active.

## Correcting Mistakes
1. If a mistake is made immediately after typing, the DEL, RUB, or RUBOUT key can be used to delete the last character.
2. If the mistake is noticed after listing the program, the `3LT` command can be used to move down and display the incorrect line. The `SMIV` command can replace the incorrect text (`MIV`) with the correct one (`MVI`).

## Exiting ED
Once the program is correct, use the command `E` to exit ED, which saves the program as `TEST.ASM`. The new file can be verified with the `DIR` and `TYPE` commands.

## Learning ED
The tutorial covers the basic commands, and more complex features of ED will be explored later. After entering and correcting the program, the next step is to move on to the assembler.

This guide serves as an introduction to using ED and ASM for assembly language programming, starting with simple tasks and building up to more complex operations.