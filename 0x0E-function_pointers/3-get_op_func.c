#include "calc.h"
#include <stdlib.h>

/**
 * get_op_func - Find the proper operator to call the proper function
 * @s: Operator to determine proper function to call
 *
 * Return: Pointer to function matching operator
 */
int (*get_op_func(char *s))(int, int)
{
	char *ops = "+-*/%";
	int (*func[])(int, int) = {op_add, op_sub, op_mul, op_div, op_mod};
	int i;

	i = 0;
	while (ops[i] != '\0')
	{
		if (ops[i] == *s)
			return (func[i]);
		i++;
	}
	return (NULL);
}
