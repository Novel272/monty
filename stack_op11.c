#include "monty.h"

/**
 * mul_nodes - Adds two elements of stack.
 * @stack: Pointer to pointing to top node stack.
 * @line_number: Interger represent line number of opcode.
 *
 * Description:add two
 * return:0
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int su;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	su = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = su;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Addstwo elements of stack.
 * @stack: Pointer to pointing to top node stack.
 * @line_number: Interger represent line number ofopcode.
 *
 * Description:add two elements
 * return:0
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int su;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	su = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = su;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
