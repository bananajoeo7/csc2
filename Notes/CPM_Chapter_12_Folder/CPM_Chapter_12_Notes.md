# CP/M Chapter 12: Console Input/Output
note to self:
- Location 5 is the entry point for the CP/M BDOS.
## Program Building Blocks:
- Each block should perform a single function, with some saying that they should only have a single entry and exit point. (Note you can have more than one entry and exit without the program collapsing)

![user/system_interface](image.png)

- CPMIO subroutines can be called directly from the main program.
- An example of a CPMIO subroutine is CO: which can be called by both the main program and at another time by an intermediate level subroutine, that had first been called by the main program.
- CPIO Subroutines fulfill the following dual function, they can, separate the user's register utilization conventions from those of the CP/M operating system, and they can manage all communication with the
outside world to be handled by the CP/M BDOS call at location 5.