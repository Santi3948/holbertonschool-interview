#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Function sum sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile2
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, a = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	printf("=\n");
	pgrid(grid1);
	a = is_not_stable(grid1);
	if (a != 0)
	{
		while (a != 0)
		{
			toople(grid1);
			a = is_not_stable(grid1);
			if (a != 0)
			{
				printf("=\n");
				pgrid(grid1);
			}
		}
	}
}

/**
 * is_not_stable - Function determine sandpile is stable
 * @grid1: sandpile 1
 * Return: 1 if not stable
 */
int is_not_stable(int grid1[3][3])
{
	int i, j;
	int a = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			a = 1;
		}
	}
	return (a);
}

/**
 * toople - Function toople for sandpiles
 * @grid1: sandpile 1
 * Return: None
 */
void toople(int grid1[3][3])
{
	int i, j, may[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				may[i][j] = 1;
			else
				may[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (may[i][j] == 1)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
				if (i + 1 <= 2)
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
				if (j + 1 <= 2)
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
			}
		}
	}
}
/**
 * pgrid - function print
 * @grid: sandpile
 * Return: No return
 */
void pgrid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
