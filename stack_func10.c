#include "monty.h"


/**
 * add_to_stack - Adds node to stack.
 * @new_node: Pointer to new node.
 * @ln: Interger represent the lines number of opcode.
 * Description:add node
 * return: 0
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tm;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tm = head;
	head = *new_node;
	head->next = tm;
	tm->prev = head;
}


/**
 * print_stack - Add  node to stack.
 * @stack: Pointer to pointer pointing to top node of stack.
 * @line_number: line number of opcode.
 *
 * Description:add node
 * return:0
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tm;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tm = *stack;
	while (tm != NULL)
	{
		printf("%d\n", tm->n);
		tm = tm->next;
	}
}

/**
 * pop_top - Adds node to stack.
 * @stack: Pointer to pointer pointing to top node of stack.
 * @line_number: Interger represent line number of opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tm = *stack;
	*stack = tm->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tm);
}

/**
 * print_top - Print top node of stack.
 * @stack: Pointer pointing to top node of stack.
 * @line_number: Interger represent line number of opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
