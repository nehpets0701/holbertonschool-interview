#include "slide_line.h"

/**
*shifts-shifts indicies
*@line:input
*@fast:fast
*@slow:slow
*/
void shift(int *line, int fast, int slow)
{
	if (line[fast] == line[slow])
	{
		line[fast] = line[slow] * 2;
		line[slow] = line[fast];
		line[fast] = 0;
	}
}

/**
*slide_line-one line 2048
*Return:1/0
*@line:input
*@size:size
*@direction:l/r
*/
int slide_line(int *line, size_t size, int direction)
{
	int i = 0, fast = 0, slow = 0, max = size - 1;

	if (direction == SLIDE_RIGHT)
		for (slow = max; slow >= 0; slow--)
		{
			for (fast = slow - 1; fast >= 0; fast--)
			{
				if (line[fast] != line[slow] && line[fast] != 0)
					break;
				shift(line, slow, fast);
			}
			for (i = slow; i != max; i++)
				if (line[i + 1] == 0)
				{
					line[i + 1] = line[i];
					line[i] = 0;
				}
		}
	else if (direction == SLIDE_LEFT)
		for (slow = 0; slow <= max; slow++)
		{
			for (fast = slow + 1; fast <= max; fast++)
			{
				if (line[fast] != line[slow] && line[fast] != 0)
					break;
				shift(line, slow, fast);
			}
			for (i = slow; i != 0; i--)
				if (line[i - 1] == 0)
				{
					line[i - 1] = line[i];
					line[i] = 0;
				}
		}
	else
		return (0);
	return (1);
}
