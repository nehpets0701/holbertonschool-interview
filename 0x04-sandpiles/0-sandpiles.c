#include "sandpiles.h"

/**
*sandpiles_sum-adds two sandpiles
*@grid1:sandpile a
*@grid2:sandpile b
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	addPiles(grid1, grid2);
	while (1)
	{
		if (isStable(grid1))
			return;

		printf("=\n");
		i = 0;
		while (i < 3)
		{
			j = 0;
			while (j < 3)
			{
				printf("%d", grid1[i][j]);
				if (j < 2)
					printf(" ");
				else
					printf("\n");
				j++;
			}
			i++;
		}
		topple(grid1, grid2);
	}
}

/**
 *isStable-is stable
 *Return: 0/1
 *@grid:input
 */
int isStable(int grid[3][3])
{
	int i = 0, j = 0;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (grid[i][j] > 3)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
*addPiles-adds piles
*@grid1:pile a
*@grid2: pile b
*/
void addPiles(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			grid1[i][j] += grid2[i][j];
			j++;
		}
		i++;
	}
}

/**
*topple-topple
*@grid1:grid1
*@grid2:grid2
*/
void topple(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	copy(grid1, grid2);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (grid1[i][j] > 3)
			{
				grid2[i][j] -= 4;
				if (i + 1 < 3)
					grid2[i + 1][j] += 1;
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (j + 1 < 3)
					grid2[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
			}
			j++;
		}
		i++;
	}
	copy(grid2, grid1);
}

/**
*copy-copies 1 to 2
*@grid1:src
*@grid2:dest
*/
void copy(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			grid2[i][j] = grid1[i][j];
			j++;
		}
		i++;
	}
}
