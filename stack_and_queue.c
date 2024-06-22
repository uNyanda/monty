#include "monty.h"

/* Global variable to store the current mode */
int mode = STACK;

/**
 * opcode_stack - Sets the format of the data to a stack (LIFO).
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'stack' opcode
 *			in a Monty bytecode file. The 'stack' opcode sets the format
 *			of the data to a stack (LIFO). This is the default behavior
 *			of the program. When switching mode from queue to stack, the
 *			front of the queue becomes the top of the stack.
 *
 * Return: void
*/
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = STACK;
}

/**
 * opcode_queue - Sets the format of the data to a queue (FIFO).
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'queue' opcode in
 *			in a Monty bytecode file. The 'queue' opcode sets the format of
 *			the data to a queue (FIFO). When switching mode from stack to
 *			queue, the top of the stack becomes the front of the queue.
 *
 * Return: void.
*/
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = QUEUE;
}
