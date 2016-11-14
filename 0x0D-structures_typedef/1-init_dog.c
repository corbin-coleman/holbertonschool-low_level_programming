#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initialize the struct dog
 * @d: pointer to struct
 * @name: Name of dog
 * @age: Age of dog
 * @owner: Name of owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
