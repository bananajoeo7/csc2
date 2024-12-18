## Study Questions #1:
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

1: First, in the calculator program you would have to let the program recognize the new operations "M" and "A". In the case of the "M" 
operation you would have to just make the current vale, lets denote it 
as Num, so ```Num = -Num```. In the case of the "A" operation you would 
first have to check if the number is greater than or less that zero, and
if its greater than zero return Num, but if its less than zero you would
 just have to make ```Num = -Num```, just like before.

2: To have the program recognize a word instead of a character, you 
would have the program check for a string instead of a charcter. 
Additionally, you would probably want to have the recieved string be 
changed to all lowercase to prevent any possibility's for 
failure.

3: First, you would have to change int variables to double variables.
 Next you would have to chaneg the input to take double values instead 
of int values, and same with the output. And finnaly change the opperations to handle double values.

4: I am unaware of how to do this, but my first step would be to 
research how to do this using some rudementary display system or use 
some game engine that supports c and c++ to use its tools to make a 
simple GUI, like godot.

5: To implement a clear command "C" you would have to let the prgram 
recognize the input for the new opperator "C". Then you would likely 
have all of your variables be global and just have a function that sets
all of the variables to 0.

6: To have your calculator use parentheses you would likely have to have 
the program take an input as a string. Next, you would have to parse 
through the string until it found each parentheses with the parse 
labeling where the parentheses is with variables like "j" and "i". Then, have the program complete the operations within the parentheses first,
and then finnaly the operators outside of the parentheses. 


## Study Questions #2:
1. What are the largest and smallest integer values in the programming environment you use? 

2. Each BigInt object will need to store the digits that represent the BigInt value. The decision to allow arbitrarily large BigInt values affects the choices for storing digits. Name one method for storing digits that will permit an arbitrary number of digits to be stored. What effect would a limit on the number of digits in a BigInt have in the design of the BigInt class? 

3. Based on your knowledge of pencil-and-paper methods for doing arithmetic, what do you think will be the most difficult arithmetic operation (+, *, ) to implement for the BigInt class? Why? 

4. Experiment with the calculator. If you enter abcd1234 when a number is expected, what happens? If you enter 1234abcd is the behavior different? What happens if you enter an operator that’s not one of the three that are implemented? 

5. List as many operations as you can that are performed on integers, but that are not included in the list of BigInt functions and operators above. 

6. (AB only) What implementation decisions would require providing a destructor, a copy constructor, and an assignment operator?

### Answers:

1: In the programming enviroment of BDS C the largest interger value is a 32 bit number and the smallest value I guess is 0 (or a -31 bit number).

2: One possible solution is the creation of a string (character array) that stores a large number. The limit to that solution is how much data the enviroment that you are using, unless there is a limit to how large a string can be made.

3: I believe that the hardest arithmetic operation would be "*" because it will likely generate the largest numbers faster, and if you use a string to store data I'm not 100% sure how easily that can be accomplished.

4: In the calc program as soon as the letter a is typed in the first case it makes the value 16706, but in the second case it just uses 1234 as the number it progresses to the next step in the program. And if I enter a different opperator, such as "/", it disregards what I just put in and asks again for an operator.

5: There is: "**", "/", "%", "()" theoretically.

6: A destructor would likely be used if incorrect input is provided, a copy constructor would likely be used when modifying the input provided, and an assignment operator would likely be used for a for loop or once valid input is provided.