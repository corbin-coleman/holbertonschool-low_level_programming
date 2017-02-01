#include <stdio.h>
/**
 * set_string - Set value of a pointer to a char
 * @s: Pointer to the pointer we are chaning
 * @to: Pointer to what we are setting it to
 */

void set_string(char **s, char *to)
{
	*s = to;
}
