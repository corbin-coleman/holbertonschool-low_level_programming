#include <stdlib.h>

/**
 * word_count - Count number of words separated by spaces in a string
 * @str: String to check
 *
 * Return: Number of words;
 */
int word_count(char *str)
{
	int count;
	int i;

	i = count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

/**
 * find_words_len - Find length of all the words in a string
 * @str: String to check length of words in
 * @words: Number of words
 *
 * Return: Combined length of words
 */
int *find_words_len(char *str, int words)
{
	int i, word, len;
	int *sizes;

	sizes = malloc(words * sizeof(int));
	if (sizes == NULL)
		return (NULL);
	i = word = 0;
	while (word < words)
	{
		if (str[i] != ' ')
		{
			len = 0;
			while (str[i] != ' ')
			{
				len++;
				i++;
			}
			len++;
			sizes[word] = len;
			word++;
		}
		i++;
	}
	return (sizes);
}

/**
 * strtow - Split a string into words
 * @str: String to split
 *
 * Return: Return pointer to an array of strings, NULL if it fails
 */
char **strtow(char *str)
{
	char **nstr;
	int words, i, j, k, cur_words, *sizes;

	if (str == NULL || *str == '\0')
		return (NULL);
	words = word_count(str);
	sizes = malloc(words * sizeof(int));
	if (sizes == NULL)
		return (NULL);
	sizes = find_words_len(str, words);
	nstr = malloc((words + 1) * sizeof(char *));
	if (nstr == NULL)
		return (NULL);
	i = j = k = 0;
	while (i < words && str[j] != '\0')
	{
		cur_words = i;
		nstr[i] = malloc(sizes[i] + sizeof(char));
		if (nstr[i] == NULL)
		{
			for (i = i - 1; i >= 0; i--)
				free(nstr[i--]);
			free(nstr);
			return (NULL);
		}
		while (str[j] != '\0' && i == cur_words)
		{
			if (str[j] != ' ')
			{
				while (str[j] != '\0' && str[j] != ' ')
				{
					nstr[i][k] = str[j]; j++; k++;
				}
				nstr[i][k] = '\0'; i++; k = 0;
			}
			j++;
		}
	}
	nstr[i] = NULL;	free(sizes);
	return (nstr);
}
