#include "monty.h"

/**
 * print_char - Print Ascii value.
 * @stack: Pointer to pointing to top node of stack.
 * @line_number: Interger represent line number of opcode.
 *
 * Description:print Ascii value
 * return:0
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		string_err(10, line_number);
	printf("%c\n", asci);
}

/**
 * print_str - Print string.
 * @stack: Pointer to pointing to top node of stack.
 * @ln: Interger represent line number of opcode.
 *
 * Description:print string
 * return:0
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asci;
	stack_t *tm;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tm = *stack;
	while (tm != NULL)
	{
		asci = tm->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tm = tm->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates first node of stack to bottom.
 * @stack: Pointer to pointing to top node of stack.
 * @ln: Interger representing the line number of opcode.
 *
 * Description:rotate first to bottom
 * return:0
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tm = *stack;
	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *stack;
	(*stack)->prev = tm;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates last node of stack to top.
 * @stack: Pointer to pointing to top node of stack.
 * @ln: Interger represent line number of opcode.
 *
 * Description:rotate last to top node
 * return:0
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tm = *stack;

	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *stack;
	tm->prev->next = NULL;
	tm->prev = NULL;
	(*stack)->prev = tm;
	(*stack) = tm;
}
