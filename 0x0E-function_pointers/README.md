Holberton School Project 0x0E Function Pointers

0-print_name.c:
	File contains a function that calls another function to print a given name using a pointer to a function.

1-array_iterator.c:
	File contains a function that iterates through an array and calls a given function on each item using a pointer to a function.

2-int_index.c:
	File contains a function that traverses an array and calls a given comparison function using a function pointer to find specific numbers, based on the given function to call.

3-calc.h:
	Header file containing prototypes and structs to be used with 3-main.c, 3-get_op_func.c, and 3-op_functions.c.

3-get_op_func.c:
	Finds the proper function from the 3-op_functions.c file to call based on the arguments passed to the 3-main.c file. The function returns a pointer to the function to call.

3-main.c:
	The main file of a program to take arguments into main and do math on them based on the given operator inputted. The file exits with an error if the program receives the incorrect number of arguments, anything other than 4, if the get_op_func function call returns NULL, or if the expected operator argument is too long to be an operator, aka greater than 1 character excluding the null character terminating byte.

3-op_functions.c:
	Contains five different functions that will do math on the arguments passed to them. The op_add function adds the args, op_sub subtracts the first arg from the second, op_mul multiplies the two args, op_div will divide the first arg by the second, op_mod will divide the first arg by the second and return the remainder. All arguments will be ints.

function_pointers.h:
	Header file containing any necessary prototypes for 0-print_name.c, 1-array_iterator.c, and 2-int_index.c.

100-main_opcodes.c:
	Function will find and print out the opcodes of the functions called in main up until the given number of bytes.
