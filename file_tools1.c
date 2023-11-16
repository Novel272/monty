#include "monty.h"

/**
 * open_file - open file
 * @file_name:file namepath
 *
 * Description:open a file
 * Return: void
 */

void open_file(char *file_nam)
{
	FILE *f = fopen(file_nam, "r");

	if (file_nam == NULL || f == NULL)
		err(2, file_nam);

	read_file(f);
	fclose(f);
}


/**
 * read_file - read file
 * @f: pointer to a file descriptor
 *
 * Description:reads a file
 * Return: void
 */

void read_file(FILE *f)
{
	int line_number, format = 0;
	char *buffe = NULL;
	size_t le = 0;

	for (line_number = 1; getline(&buffe, &le, f) != -1; line_number++)
	{
		format = parse_line(buffe, line_number, format);
	}
	free(buffe);
}


/**
 * parse_line - Separate each line to tokens to determine
 * which function to call
 * @buffe: line from file
 * @line_numbe: line number in file
 * @format:format storage. If 0 Nodes be entered as stack.
 * if 1 nodes will enter as queue.
 *
 * Description:seperate each line
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffe, int line_numbe, int format)
{
	char *opcod, *valu;
	const char *delim = "\n ";

	if (buffe == NULL)
		err(4);

	opcod = strtok(buffe, delim);
	if (opcod == NULL)
		return (format);
	valu = strtok(NULL, delim);

	if (strcmp(opcod, "stack") == 0)
		return (0);
	if (strcmp(opcod, "queue") == 0)
		return (1);

	find_func(opcod, valu, line_numbe, format);
	return (format);
}

/**
 * find_func - find appropriate function for opcode
 * @opcod: op code
 * @valu:opcode argument
 * @format:storages formats. If 0 Nodes will enter as stack.
 * if 1 nodes will enter as queue.
 * @ln: line numbers
 *
 * Description:find function for opcode
 * Return: void
 */
void find_func(char *opcod, char *valu, int l, int format)
{
	int x;
	int fla;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcod[0] == '#')
		return;

	for (fla = 1, x = 0; func_list[x].opcod != NULL; x++)
	{
		if (strcmp(opcod, func_list[x].opcod) == 0)
		{
			call_fun(func_list[x].f, opcod, valu, l, format);
			fla = 0;
		}
	}
	if (fla == 1)
		err(3, l, opcod);
}


/**
 * call_fun - Call required function.
 * @func: Pointer to function that about to be called.
 * @o: string represent opcode.
 * @va: string represen numeric value.
 * @l: line numeber for instruction.
 * @forma: Format specifier. If 0 Nodes will enter as stack.
 * if 1 nodes will enter as queue.
 *
 * Description:call requried function
 * return: void
 */
void call_fun(op_func func, char *o, char *va, int l, int forma)
{
	stack_t *node;
	int fla;
	int x;

	fla = 1;
	if (strcmp(o, "push") == 0)
	{
		if (va != NULL && va[0] == '-')
		{
			va = va + 1;
			fla = -1;
		}
		if (va == NULL)
			err(5, l);
		for (x = 0; va[x] != '\0'; x++)
		{
			if (isdigit(va[x]) == 0)
				err(5, l);
		}
		node = create_node(atoi(va) * fla);
		if (forma == 0)
			func(&node, l);
		if (forma == 1)
			add_to_queue(&node, l);
	}
	else
		func(&head, l);
}
