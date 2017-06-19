#include "maze.h"

void print_win(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("     \\  /  __   |     |\n");
	printf("      \\/  /  \\  |     |\n");
	printf("      /  |    | |     |\n");
	printf("     /    \\__/   \\___/\n\n");
	printf("\\      /\\      / ------- |\\   |\n");
	printf(" \\    /  \\    /     |    | \\  |\n");
	printf("  \\  /    \\  /      |    |  \\ |\n");
	printf("   \\/      \\/    ------- |   \\|\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

int check_win(double_s play, int_s win, int *win_value)
{
	if ((int) play.x == win.x && (int) play.y == win.y)
	{
		*win_value = 1;
		return (1);
	}
	return (0);
}
