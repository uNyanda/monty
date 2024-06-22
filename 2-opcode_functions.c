#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *		of the stack by the top element.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'mod'
 *			opcode in a Monty bytecode file.
 *			The 'mod' opcode computes the rest of the division
 *			of the second top element of the stack by the top
 *			element of the stack. If the stack contains less
 *			than two elements, it prints an error message and
 *			exits with the status EXIT_FAILURE. If the top
 *			element of the stack is 0, it prints an error
 *			message and exits with the status EXIT_FAILURE.
 *			The result is stored in the second top element
 *			of the stack, and the top element is removed.
 *
 * Return: void.
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(line_number, "can't mod, stack too short", NULL);
	}

	/* check if the top element of the stack is 0 */
	if ((*stack)->n == 0)
	{
		handle_error(line_number, "division by zero", NULL);
	}

	/* COMPUTE THE REST OF THE DIVISION OF THE SECOND TOP ELEMENT BY */
	/* THE TOP ELEMENT */
	(*stack)->next->n %= (*stack)->n;

	/* remove the top element of the stack */
	tmp = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pchar - Prints the char at the top of the stack, followed by a
 *		new line.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'pchar'
 *			opcode in a Monty bytecode file.
 *			The 'pchar' opcode prints the char at the top of the
 *			stack, followed by a new line. The integer stored at
 *			the top of the stack is treated as the ascii value of
 *			character to be printed.
 *			If the value is not in the ascii table, it prints an
 *			error message and exits with the status EXIT_FAILURE.
 *			If the stack is empty, it prints an error message and
 *			exits with the status EXIT_FAILURE.
 *
 * Return: void.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	/* check if the stack is empty */
	if (*stack == NULL)
	{
		handle_error(line_number, "can't pchar, stack empty", NULL);
	}

	/* CHECK IF THE VALUE IS IN THE ASCII TABLE */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		handle_error(line_number, "can't pchar, value out of range", NULL);
	}

	/* PRINT THE CHAR AT THE TOP OF THE STACK */
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'pstr'
 *			opcode in a Monty bytecode file.
 *			The 'pstr' opcode prints the string starting at the top
 *			of the stack, followed by a new line. The integer stored
 *			at each element of the stack is treated as the ascii value
 *			character to be printed. The string stops when either the
 *			stack is over, the value of the element is 0, or the value
 *			of the element is not a printable character.
 *
 * Return: void.
*/
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;

	/* loop through the stack until we hit a NULL pointer (end of stack), */
	/* a node with a value of 0, or node with a non-printabe character */
	while (tmp != NULL && tmp->n > 0 && tmp->n <= 127)
	{
		/* print the ascii char presented by the node's value */
		printf("%c", tmp->n);
		tmp = tmp->next;  /* move to next node */
	}
	printf("\n");  /* new line at the end per requirements */

}

/**
 * rotl - Rotates the stack to the top.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'rot1' opcode
 *			in a Monty bytecode file. The 'rot1' opcode rotates the stack
 *			to the top. The top element of the stack becomes the last one,
 *			and the second top element of the stack becomes the first one.
 *			'rot1' never fails.
 *
 * Return: void.
*/
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	/* start at the top of the stack (always) */
	stack_t *tmp = *stack;
	stack_t *old_top;

	/* if the stack is empty or has one node, nothing to rotate */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	/* store the old top of the stack node */
	old_top = *stack;

	/* move the top of the stack to the second node */
	*stack = (*stack)->next;
	/* the new top of the stack has no previous node */
	(*stack)->prev = NULL;

	/* find the last node */
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	/* make the old 'top-of-the-stack' node, the last one */
	tmp->next = old_top;
	/* since it's the last node now, its 'next' pointer should be NULL */
	old_top->next = NULL;
	/* its 'prev' pointer should be what was previously the last node */
	old_top->prev = tmp;
}

/**
 * rotr - Rotates the stack to the bottom.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'rotr' opcode
 *			in a Monty bytecode file. The 'rotr' opcode rotates the stack
 *			to the bottom. The last element of the stack becomes the top
 *			element of the stack.
 *			'rotr' never fails.
 *
 * Return: void.
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;  /* start at the top of the stack (always) */

	/* if the stack is empty or has only one node, nothing to rotate */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	/* find the last node in the stack */
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	/* make the last node, the new 'top-of-the-stack' node */
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
