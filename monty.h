#ifndef MONTY_H
#define MONTY_H

/* Constants to represent the two modes */
#define STACK 0
#define QUEUE 1

#define _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>

/* extern declaration of the global variable */
extern int mode;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* 0-opcode_functions.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* 1-opcode_functions.c */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* 2-opcode_functions.c */
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* 0-functions.c */
bool is_integer(char *arg);
void handle_error(int line_number, char *message, char *opcode);
FILE *open_file(char *filename);

/* execute_opcodes.c */
void execute_opcode(char *opcode, char *arg, stack_t **stack,
unsigned int line_number);

/* stack_and_queue.c */
void opcode_stack(stack_t **stack, __attribute__((unused))unsigned int line_number);
void opcode_queue(stack_t **stack, __attribute__((unused))unsigned int line_number);

/* memory.c */
void *allocate_memory(size_t size, unsigned int line_number);
void free_stack(stack_t **stack);

#endif
