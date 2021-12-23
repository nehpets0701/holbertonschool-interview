#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * main - print out the argument count.
 * @argc: argument count.
 * @argv: argument vector array.
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int i, j, len1, len2, carry, sum, num1, num2, idx1 = 0, idx2 = 0;
	int buffer[100000] = {0};

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		num1 = argv[1][i] - '0';
		idx2 = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			num2 = argv[2][j] - '0';
			sum = num1 * num2 + buffer[idx1 + idx2] + carry;
			carry = sum / 10;
			buffer[idx1 + idx2] = sum % 10;
			idx2++;
		}
		if (carry > 0)
			buffer[idx1 + idx2] += carry;
		idx1++;
	}
	i = 99999;
	while (i >= 0 && buffer[i] == 0)
		i--;
	if (i == -1)
	{
		printf("0\n");
		return (0);
	}
	for (; i >= 0; i--)
		printf("%d", buffer[i]);
	printf("\n");
	return (0);
}
