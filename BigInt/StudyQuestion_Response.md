## Study Questions:
1. Suppose you want to add unary operations (i.e., ones requiring only one operand) to the calculator. 
For example, we might add "M" to indicate unary minus (i.e., change the sign of the old value) and "A" 
to indicate absolute value. What changes would need to be made to the program? 

2. Suppose that words rather than single character symbols are to be used for the operators (e.g., the 
user types "times" instead of "*"). Where in the program would the necessary changes occur? 

3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where 
would changes need to be made? 

4. Most modern systems support graphical displays and mouse (or other pointer) input. Rewrite the 
Calculator program to take advantage of these features to produce an on-screen push-button 
calculator (this is a large programming project).

5. Show how a new command, "C", which acts like the "Clear" command on a calculator could be 
implemented. The clear command sets the current value to zero. 6. (AB only) How could the 
calculator be modified to allow the use of parentheses to control the order of operations?

6. (AB only) How could the calculator be modified to allow the use of parentheses to control the 
order of operations?

### Answers:

1: First, in the calculator program you would have to let the program recognize the new operations 
"M" and "A". In the case of the "M" operation you would have to just make the current vale, lets 
denote it as Num, so ```Num = -Num```. In the case of the "A" operation you would first have to 
check if the number is greater than or less that zero, and if its greater than zero return Num, 
but if its less than zero you would just have to make ```Num = -Num```, just like before.

2: To have the program recognize a word instead of a character, you would have the program check 
for a string instead of a charcter. Additionally, you would probably want to have the recieved 
string be changed to all lowercase to prevent any possibility's for failure.