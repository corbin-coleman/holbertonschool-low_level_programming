#include <stdlib.h>

/**
 * alloc_grid - Create a 2 dimensional array
 * @width: Width of grid, aka # of columns
 * @height: Height of grid, aka # of rows
 *
 * Return: Pointer to 2D array, NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	i = 0;
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);
	while (i < height)
	{
		grid[i] = malloc(width * sizeof(int *));
		if (grid[i] == NULL)
			return (NULL);
		j = 0;
		while (j < width)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
