#include "menger.h"

/**
*menger-prints menger sponge
*@level:size
*/
void menger(int level)
{
	int i = 0, j, sub, size = 1;

	if (level < 0)
		return;

	while (i < level)
	{
		i++;
		size *= 3;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			for (sub = size / 3; sub; sub /= 3)
				if ((i % (sub * 3)) / sub == 1 && (j % (sub * 3)) / sub == 1)
					break;
			if (sub)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
