# **0x19. C - Stacks, Queues - LIFO, FIFO**&emsp;<sup><ins>:handshake:TEAM PROJECT:handshake:</ins></sup>

## This directory contains files that can be tested for C - Stacks, Queues - LIFO, FIFO.

:file_folder: : [monty.h](monty.h) - This is a header file that contains all prototypes for functions written for the project.

### <ins>Tasks</ins>

> [!TIP]
> Compile with the following GCC flags:
```shell
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

### 0. **push, pall**
Implement the `push` and `pall` opcodes.

**The push opcode**<br>
The opcode `push` pushes an element to the stack.
- Usage : `push <int>`
  - where `<int>` is an integer
- if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where is the line number in the file
- You won't have to deal with overflows. Use the `atoi` function

**The pall opcode**<br>
The opcode `pall` prints all the values on the stack, starting from the top of the stack.
- Usage `pall`
- If the stack is empty, don't print anything

### 1. **pint**
Implement the `pint` opcode.

**The pint opcode**<br>
The opcode `pint` prints the value at the top of the stack, followed by a new line.
- Usage; `pint`
- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 2. **pop**
Implement the `pop` opcode.

**The pop opcode**<br>
The opcode `pop` removes the top element of the stack.
- Usage: `pop`
- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 3. **swap**
Implement the `swap` opcode.

**The swap opcode**<br>
The opcode `swap` swaps the top two elements of the stack.
- Usage: `swap`
- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 4. **add**
Implement the `add` opcode

**The add opcode**<br>
The opcode `add` adds the top two elements of the stack.
- Usage: `add`
- If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

### 5. **nop**
Implement the `nop` opcode.

**The nop opcode**<br>
The opcode `nop` doesn’t do anything.
- Usage: nop

### 6. **sub** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `sub` opcode.

**The sub opcode**<br>
The opcode `sub` subtracts the top element of the stack from the second top element of the stack.
- Usage: `sub`
- If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

### 7. **div** &emsp;<sup>:fire:advanced task:fire:</sup> 
Implement the `div` opcode.

**The div opcode**<br>
The opcode `div` divides the second top element of the stack by the top element of the stack
- Usage: `div`
- If the stack contains less than two elements, print the error message `L<line_number>: can't dive, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter
- If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 8. **mul** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `mul` opcode.

**The mul opcode**<br>
The opcode `mul` multiples the second top element of the stack with the top element of the stack.
- Usage: `mul`
- If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

### 9. **mod** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `mod` opcode.

**The mod opcode**<br>
The opcode `mod` computes the rest of the division of the second element of the stack by the top element of the stack.
- Usage: `mod`
- If the stack contains less than two elements, print the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter
- If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 10. **comments** &emsp;<sup>:fire:advanced task:fire:</sup>
Every good language comes with the capability of commenting. When the first non-space character of a line is `#`, treat this line as a comment (don't do anything).

### 11. **pchar** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `pchar` opcode

**The pchar opcode**
The opcode `pchar` prints the char at the top of the stack, followed by a new line.
- Usage: `pchar`
- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- If the value is not in the ascii table (man ascii) print the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If the stack is empty, print the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status  `EXIT_FAILURE`

### 12. **pstr** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `pstr` opcode.

**The pstr opcode**<br>
The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.
- Usage: `pstr`
- The integer stored in each element of the stack is treated as the ascii value character of the character to be printed
- The string stops when either:
  - the stack is over
  - the value of the element is 0
  - the value of the element is not in the ascii table
- If the stack is empty, print only a new line

### 13. **rot1** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `rot1` opcode.

**The rot1 opcode**<vr>
The opcode `rot1` rotates the stack to the top.
- Usage: `rot1`
- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
- `rot1` never fails

### 14. **rotr** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `rotr` opcode.

**The rotr opcode**<br>
The opcode `rotr` rotates the stack to the bottom.
- Usage: `rotr`
- The last element of the stack becomes the top element of the stack
- `rotr` never fails

### 15. **stack, queue** &emsp;<sup>:fire:advanced task:fire:</sup>
Implement the `stack` and `queue` opcodes.

**The stack opcode**<br>
The opcode `stack` sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- Usage: `stack`

**The queue opcode**<br>
The opcode `queue` sets the format of the data to a queue (FIFO).
- Usage: `queue`

When switching mode:
- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack

### 16. **Brainf\*ck** &emsp;<sup>:fire:advanced task:fire:</sup>
Write a Brainf*ck script that prints `School`, followed by a new line.
- All your Brainf*ck files, should be stored inside the `bf` sub directory
- You can install the `bf` interpreter to test your code: `sudo apt-get install bf`
- :file_folder:  [1000-school.bf](1000-school.bf)

### 17. **Add two digits** &emsp;<sup>:fire:advanced task:fire:</sup>
Add two digits given by the user.
- Read the two digits from stdin, add them, and print the result
- The total of the two digits will be one digit-long(<10)
- :file_folder: [1001-add.bf](1001-add.bf)

### 18. **Multiplication** &emsp;<sup>:fire:advanced task:fire:</sup>
Multiply two digits given by the user.
- Read the two digits from stdin, multiply them, and print the result
- The result of the multiplication will be one digit-long(<10)
- :file_folder: [1002-mul.bf](1003-mul.bf)

### 19. **Multiplication level up** &emsp;<sup>:fire:advanced task:fire:</sup>
Multiply two digits given by the user.
- Read the two digits from stdin, multiply them, and print the result, followed by a new line
- :file_folder: [1003-mul.bf](1003-mul.bf)
