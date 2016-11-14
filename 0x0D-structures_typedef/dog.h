/**
 * struct dog - Create a struct of a dog
 * @name: Dog's name
 * @age: Age of the dog
 * @owner: Dog's owner
 */
typedef struct dog {
	char *name;
	float age;
	char *owner;
} dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
