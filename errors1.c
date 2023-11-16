#include "monty.h"

/**
 * err - Print appropiate error message determined by error code.
 * @error_code: The error codes are :
 * (1) => user does not give any file or more than file to program.
 * (2) => file provided is not file that can be opened or read.
 * (3) => file provided has an invalid instruction.
 * (4) => program is unable to malloc more memory.
 * (5) => parameter passed to the instruction "push" is not int.
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list a;
	char *o;
	int l_nu;

	va_start(a, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(a, char *));
			break;
		case 3:
			l_nu = va_arg(a, int);
			o = va_arg(a, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_nu, o);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(a, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handle error.
 * @error_code: error codes are :
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 * (9) => Division / zero.
 */
void more_err(int error_code, ...)
{
	va_list a;
	char *o;
	int l_nu;

	va_start(a, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(a, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(a, int));
			break;
		case 8:
			l_nu = va_arg(a, unsigned int);
			o = va_arg(a, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_nu, o);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handle error.
 * @error_code: error codes are:
 * (10) ~> number inside node is outside ASCII bounds.
 * (11) ~> stack empty.
 */
void string_err(int error_code, ...)
{
	va_list a;
	int l_nu;

	va_start(a, error_code);
	l_nu = va_arg(a, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_nu);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_nu);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
