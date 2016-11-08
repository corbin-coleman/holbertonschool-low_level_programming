#include <stdlib.h>

/**
 * free_grid - Free memory allocated to a previoiusly created 2D array
 * @grid: The 2D array to free memory from
 * @height: The height of the 2D array
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	height++;
	free(grid);
}
