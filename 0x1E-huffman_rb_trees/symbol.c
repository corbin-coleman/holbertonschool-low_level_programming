#include "huffman.h"

/**
 * symbol_create - Create a symbol_t data structure
 * @data: Data to be stored in structure
 * @freq: Frequency associated w/ that data
 * Return: Pointer to created structure, NULL if it fails
 **/
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_symbol;

	new_symbol = malloc(sizeof(symbol_t));
	if (new_symbol == NULL)
		return (NULL);
	new_symbol->data = data;
	new_symbol->freq = freq;
	return (new_symbol);
}
