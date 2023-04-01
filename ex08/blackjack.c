# include <stdio.h>
# include <string.h>

int	ft_char_isinset(const char *set, const char c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv) {
	int	i;
	int	sum;

	i = 0;
	if (argc < 2) {
		printf("missing parameters\n");
		return (0);
	} else {
		while (i < strlen(argv[1])) {
			if (ft_char_isinset("23456789TJDKA", argv[1][i]) == 0) {
				printf("wrong arguments\n");
				return (0);
			}
			i++;
		}
	}

	i = 0;
	sum = 0;
	while (i < strlen(argv[1])) {
		if (argv[1] && argv[1][i] && argv[1][i] >= '2' && argv[1][i] <= '9') {
			sum += argv[1][i] - 48;
		}
		else if ((argv[1] && argv[1][i]) && (argv[1][i] == 'T' || argv[1][i] == 'J' || argv[1][i] == 'D'
			|| argv[1][i] == 'K')) {
			sum += 10;
			}
		else if ((argv[1] && argv[1][i] && argv[1][i] == 'A')) {
			if (sum > 21 || sum + 11 > 21)
				sum += 1;
			else
				sum += 11;
		}
		i++;
	}

	if (sum == 21)
		printf("Blackjack!\n");
	else
		printf("%d\n", sum);
	return (0);
}