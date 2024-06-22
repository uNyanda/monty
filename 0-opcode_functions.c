#include "monty.h"

/**
 * push - Pushes an element to the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The value of the new element.
 *
 * Description: This function is designed to implement the
 *			'push' opcode in a Monty bytecode file.
 *			The 'push' opcode pushes an element to the stack.
 *			If memory allocation fails, it prints an error
 *			message and exits with the status EXIT_FAILURE.
 *
 * Return: void.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *last = *stack;

	/* allocate memory for a new node */
	new = allocate_memory(sizeof(stack_t), line_number);

	new->n = line_number;
	new->prev = NULL;
	new->next = NULL;

	if (*stack != NULL)
	{
		if (mode == STACK)
		{
			/* add the 'new' node at the top of the stack */
			new->next = *stack;
			(*stack)->prev = new;
			*stack = new;
		}
		else
		{
			/* add the 'new' node at the end of the queue */
			while (last->next != NULL)
			{
				last = last->next;
			}
			last->next = new;
			new->prev = last;
		}
	}
	else
	{
		*stack = new;
	}
}

/**
 * pall - Prints all values on the stack, starting from the top of the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'pall'
 *			opcode in a Monty bytecode file.
 *			The 'pall' opcode prints all values on the stack,
 *			starting from the top of the stack.
 *
 * Return: void.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the
 *			'pint' opcode in a Monty bytecode file.
 *			The 'pint' opcode prints the value at the top
 *			of the stack, followed by a new line. If the
 *			stack is empty, it prints an error message and
 *			exits with the status EXIT_FAILURE.
 *
 * Return: void.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	/* check if the stack is empty */
	if (*stack == NULL)
	{
		handle_error(line_number, "can't pint, stack empty", NULL);
	}

	/* print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the
 *			'pop' opcode in a Monty bytecode file.
 *			The 'pop' opcode removes the top element of the
 *			stack. If the stack is empty, it prints an error
 *			message and exits with the status EXIT_FAILURE.
 *
 * Return: void.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* check if the stack is empty */
	if (*stack == NULL)
	{
		handle_error(line_number, "can't pop an empty stack", NULL);
	}

	tmp = *stack;

	if (mode == STACK || (*stack)->next == NULL)
	{
		/* remove the top element of the stack */
		*stack = (*stack)->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
	}
	else
	{
		/* find the last node in the queue */
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		/* remove the last element of the queue */
		if (tmp->prev != NULL)
		{
			tmp->prev->next = NULL;
		}
	}
	free(tmp);
}

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the node is located.
 *
 * Description: This function is designed to implement the 'swap'
 *			opcode in Monty bytecode file.
 *			The 'swap' opcode swaps the top two elements of the
 *			stack. If the stack contains less than two elements,
 *			it prints an error message and exits with the status
 *			EXIT_FAILURE.
 *
 * Return: void.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	/* check if the stack contains less than 2 elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(line_number, "can't swap, stack too short", NULL);
	}

	if (mode == STACK)
	{
		/* swaps the 2 elements of the stack */
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		/* swaps the front and second elements of the queue */
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
