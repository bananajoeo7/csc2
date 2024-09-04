## Part A
### Switches: 
  - **ON-OFF switch:** controls power, with the OFF position also clearing memory.
  - **STOP-RUN switch:** starts or stops program execution.
  - **SINGLE STEP switch:** processes one machine instruction at a time.
  - **EXAMINE-EXAMINE NEXT switch:** displays memory contents, while **DEPOSIT-DEPOSIT NEXT** loads data into memory.
  - **RESET-CLR switch:** resets the program counter, and **PROTECT-UNPROTECT** prevents or allows changes to memory.
  - **AUX switches:** are for future peripherals, while **DATA/ADDRESS switches** are used to enter data or memory addresses.

### LED Indicators: 
  LEDs show the status of the computer, with various LEDs indicating memory addresses, data, interrupts, protection, CPU status, and more.

Note: Why in the world is Hold HLDA and Halt HLTA, number 1 they both are 4 letter words, and number 2 the Halt has the same exact letters. (why are computer nerds so difficult?)


## Part B
- A simple program to add two numbers and store the result is used to demonstrate loading a program into memory. The program's mnemonic instructions are explained, and their corresponding bit patterns are entered into the machine through the front panel switches. After loading the program, data is entered into specified memory addresses, and the program is run by toggling the appropriate switches.

## Part C
- Memory management is crucial, especially when programming in machine language. A technique called **memory mapping** is recommended, where different blocks of memory are reserved for specific purposes like programs, subroutines, and data. Keeping track of memory usage helps prevent accidental data loss or overwriting.

## Part D
- The Altair 8800 uses various memory addressing methods, including **direct addressing**, **register pair addressing**, **Stack Pointer addressing**, **immediate addressing**, and **stack addressing of subroutines**. Each method involves specific instructions and memory management techniques, which are crucial for effective programming.

## Part E
- Check your program for issues and don't be stupid.
- **Using NOPs:** The NOP (No Operation) instruction can be strategically placed in a program to allow for easy insertion of new instructions during debugging.
- **Debugging Programs:** Use the SINGLE STEP switch to debug by examining the program cycle by cycle, so you can detect errors in the programs logic and/or organization.