#include "monty.h"

/**
 * is_integer - function checks for an integer.
 *
 * @arg: pointer to the integer to check.
 *
 * Return: true if it is an integer, else false.
*/
bool is_integer(char *arg)
{
	int i = 0;

	if (arg == NULL)
	{
		return (false);
	}

	if (arg[0] == '-')
	{
		i = 1;
	}

	for (; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]))
		{
			return (false);
		}
	}
	return (true);
}

/**
 * handle_error - handles errors by printing an error message
 *			and exiting the program.
 *
 * @line_number: the line number to where the error occured.
 * @message: the error message to be printed.
 * @opcode: the opcode.
 *
 * Description: This function takes a line number and an
 *			error message as arguments. It prints the
 *			error message to stderr with the lne number,
 *			and then exits the program with a failure status.
 *
 * Return: void.
*/
void handle_error(int line_number, char *message, char *opcode)
{
	if (line_number == 0)
	{
		fprintf(stderr, "%s\n", message);
	}
	else if (opcode == NULL)
	{
		fprintf(stderr, "L%d: %s\n", line_number, message);
	}
	else
	{
		fprintf(stderr, "L%d: %s %s\n", line_number, message, opcode);
	}
	exit(EXIT_FAILURE);
}

/**
 * open_file - Opens a file and handles errors.
 *
 * @filename: The name of the file to open.
 *
 * Description: This function opens a file with the given
 *			filename. If the file cannot be opened, it
 *			calls the handle_error function to print an
 *			error message and exit the program.
 *
 * Return: a pointer to the opened file.
*/
FILE *open_file(char *filename)
{
	char error_message[256];
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		snprintf(error_message, sizeof(error_message),
				"Error: Can't open file %s", filename);
		handle_error(0, error_message, NULL);
	}
	return (file);
}
