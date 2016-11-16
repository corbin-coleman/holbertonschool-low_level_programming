/**
 * print_name - Print the given name
 * @name: Name to print
 * @f: Pointer to void function, taking a char * as arg
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
