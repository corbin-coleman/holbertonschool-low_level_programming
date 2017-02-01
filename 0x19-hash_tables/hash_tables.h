#ifndef HASH_H
#define HASH_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * @key : The key, string
 * The key is unique in the HashTable
 * 
 * @value : The value corresponding to a key
 * 
 * @next : A pointer to the next node of the list
 */
typedef struct hash_node_s
{
  char *key;
  char *value;
  struct hash_node_s *next;
} hash_node_t;

/*
 * @size: The size of the array
 * 
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
  unsigned long int size;
  hash_node_t **array;
} hash_table_t;


hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
int check_list(char *key, hash_table_t *ht, unsigned long int index, char *value);
#endif
