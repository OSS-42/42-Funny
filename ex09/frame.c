# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	ft_dbl_ptr_free(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i]) {
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

static unsigned int	ft_wordcount(char *s, char c)
{
	unsigned int	i;
	unsigned int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i]) {
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

static char	*ft_wordstring(char *s, int i, unsigned int wordlen)
{
	char			*word;
	unsigned int	pos;

	pos = 0;
	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	while (pos < wordlen) {
		word[pos] = s[i];
		pos++;
		i++;
	}
	word[pos] = '\0';
	return (word);
}

static unsigned int	ft_wordlen(char *s, int i, char c)
{
	unsigned int	wordlen;

	wordlen = 0;
	while (s[i + wordlen] && s[i + wordlen] != c)
		wordlen++;
	return (wordlen);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	unsigned int	row;
	char			**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	row = 0;
	while (s[i]) {
		while (s[i] == c)
			i++;
		if (s[i]) {
			tab[row] = ft_wordstring((char *)s, i, ft_wordlen((char *)s, i, c));
			row++;
			i = i + ft_wordlen((char *)s, i, c);
		}
	}
	tab[row] = NULL;
	return (tab);
}

void	frame(char *argv){
	int		i;
	int		maxlen;
	char	**wordslist;

	i = 0;
	maxlen = 0;
	wordslist = NULL;
	wordslist = ft_split(argv, ' ');

	while (wordslist && wordslist[i]) {
		if (strlen(wordslist[i]) > maxlen)
			maxlen = strlen(wordslist[i]);
		i++;
	}
	i = 0;
	if (wordslist && wordslist[i]) {
		for (int j = 0; j < maxlen + 4; j++) {
				printf("*");
			}
		printf("\n");
		while (wordslist && wordslist[i]) {
			printf("* ");
			printf("%s", wordslist[i]);
			for (int j = strlen(wordslist[i]) + 2; j < maxlen + 3; j++) {
				printf(" ");
			}
			printf("*");
			printf("\n");
			i++;
		}
		for (int j = 0; j < maxlen + 4; j++) {
				printf("*");
			}
			printf("\n");
		ft_dbl_ptr_free((void **)wordslist);
	}
	return ;
}

int	main(int argc, char **argv) {
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	else {
		while (argv && argv[i]) {
			frame(argv[i]);
			i++;
		}
	}
	return (0);
}