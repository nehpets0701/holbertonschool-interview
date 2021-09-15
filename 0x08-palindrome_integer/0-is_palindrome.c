#include "palindrome.h"

/**
*is_palindrome-is palindrome?
*@n:input
*Return: 0/1
*/
int is_palindrome(unsigned long n)
{
	int remainder, original, rev = 0;

	original = n;

	while (n != 0)
	{
		remainder = n % 10;
		rev = rev * 10 + remainder;
		n = n / 10;
	}

	if (original == rev)
		return (1);
	else
		return (0);
}
