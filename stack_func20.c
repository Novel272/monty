#include "monty.h"

/**
 * nop - Do nothing.
 * @stack: Pointer to pointing to top node of stack.
 * @line_number: Interger represent line number of opcode.
 *
 * Description:do nothing
 * returnn :0
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps top two elements of stack.
 * @stack: Pointer to pointing to top node of  stack.
 * @line_number: Interger represent line number of opcode.
 *
 * Description:swap two elements
 * return:0
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tm = (*stack)->next;
	(*stack)->next = tm->next;
	if (tm->next != NULL)
		tm->next->prev = *stack;
	tm->next = *stack;
	(*stack)->prev = tm;
	tm->prev = NULL;
	*stack = tm;
}

/**
 * add_nodes - Adds top two elements of stack.
 * @stack: Pointer to pointing to top node of stack.
 * @line_number: Interger represent line number of opcode.
 *
 * Description:add two elements
 * return:0
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int su;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	su = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = su;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds top two elements of stack.
 * @stack: Pointer to pointing to top node of stack.
 * @line_number: Interger represent line number of opcode.
 *
 * Description:adds top new elements
 * return:0
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int su;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	su = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = su;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds top two elements of stack.
 * @stack: Pointer to pointing to top node of stack.
 * @line_number: Interger represnt line number of opcode.
 *
 * Description:add top new elements
 * retrun:0
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int su;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	su = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = su;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
