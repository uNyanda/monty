#include "monty.h"

/**
 * main - main function for the monty code.
 *
 * @argc: argument count (counts the number of arguments supplied.)
 * @argv: argument vectore (array of arguments supplied.)
 * Description: testing the monty codes.
 *
 * Return: always 0.
*/
int main(int argc, char **argv)
{
	char *line = NULL, *opcode, *arg, *start;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	FILE *file;
	stack_t *stack = NULL;

	/* check if the correct number of arguments was passed. */
	if (argc != 2)
		handle_error(0, "USAGE: monty file", NULL);

	/* open the Monty bytcode file */
	file = open_file(argv[1]);

	/* Parse the file and execute the opcodes */
	while ((read = getline(&line, &len, file)) != -1)
	{
		/* skip leading spaces */
		start = line;
		while (*start == ' ')
			start++;

		/* if the first non-space character is '#', skip the line */
		if (*start == '#')
			continue;

		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
			continue;

		arg = strtok(NULL, " \t\n");
		execute_opcode(opcode, arg, &stack, line_number);
	}
	free(line);
	free_stack(&stack);

	/* close the file */
	fclose(file);
	return (EXIT_SUCCESS);
}
