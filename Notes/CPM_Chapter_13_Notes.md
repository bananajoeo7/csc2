# CP/M Chapter 13: Buffed Input/Output
## Saving and Creating Backup Files
- <b/>Importance of Backup</b>: Always save a copy of fully debugged code to avoid data loss due to unexpected issues (e.g., power glitch, dust on disk).
- <b/>Temporary .BAK Files</b>: Created by the editor (ED), used as temporary backups during editing, and periodically deleted to save space.
- <b/>Permanent Backups</b>: Recommended to use a separate disk for permanent backups with a unique file type (e.g., `.C12`) that won't conflict with `.BAK` files.
- </b>Example Command</b>: 
  - Save backup on another disk:
    ```
    PIP B:CPMIO.C12=CPMIO.ASM
    ```
  - To restore as an `.ASM` file on drive A:
    ```
    PIP A:CPMIO.ASM=B:CPMIO.C12
    ```

## Using Library (.LIB) Files
- </b>Purpose of .LIB Files</b>: Allows for smaller files to work with while editing; merge into the main source file once finalized.
- <b/>Creating Library Files</b>:
  - Enter text for new routines into `.LIB` files instead of the original source for efficiency.
- <b/>Inserting .LIB Files in ED</b>:
  - Use the `R` (Read) command in ED to insert `.LIB` files at the current pointer position.
  - Command format:
    ```
    RFILENAME
    ```

## Understanding Key Subroutines
- <b/>CCRLF/<b>: Outputs a new line (Carriage Return and Line Feed) using the `CO:` subroutine; includes optimizations to save space.
- <b/>COMSG</b>: Displays a line of text by looping through each character in the buffer.