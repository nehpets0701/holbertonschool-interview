#include "substring.h"


/**
 * find_substring - find all possible substrings
 * @s: string
 * @words: array of words
 * @nb_words: number of elements
 * @n: output
 * Return: sunstring
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, s_len, nb_cpy = nb_words, *inds, i, j;
	int found = 0, used;

	if (s == NULL || words == NULL || nb_words == 0 || n == NULL)
		return (NULL);
	s_len = strlen(s);
	len = strlen(words[0]);
	inds = malloc(s_len * sizeof(int));
	if (inds == NULL)
		return (NULL);
	for (i = 0; i <= s_len - nb_words * len; i++)
	{
		found = 0, used = 0;
		for (j = 0; j < nb_words; j++)
		{
			if ((found & (1 << j)) == 0 &&
				!strncmp(&s[i + used * len], words[j], len))
			{
				found = found | 1 << j;
				j = -1;
				used++;
			}
		}
		if (found == (1 << nb_cpy) - 1)
		{
			inds[*n] = i;
			(*n)++;
		}
	}
	return (inds);
}
