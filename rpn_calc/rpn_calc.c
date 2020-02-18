#include <stdlib.h>
#include <stdio.h>

typedef struct	s_rpn
{
	char op;
	int nb;
}				t_rpn;

int	is_ope(char * str, int *i)
{
	//printf("[%c]\n", c);
	char c = str[*i];
	if (str[*i + 1] == ' ' || !str[*i + 1])
	{
		if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
		{
			*i += 1;
			return (1);
		}
	}
	return (0);
}

int	is_nb(char *str, int *index)
{
	int i;
	int check = 0;

	i = *index;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			check = 1;
		else if (str[i] == ' ' || !str[i])
		{
			if (check == 1)
				*index = i;
			return (check);
		}
		else 
			return (0);
		i++;
	}
	return (0);
}

int valid_arg(char *str)
{
	int i = 0;
	int check = 0;
	int count = 0;

	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (is_nb(str, &i))
			check++;
		else if (is_ope(str, &i))
			check--;
		else 
			return (0);
		if (check < 1)
			return (0);
		while (str[i] == ' ')
			i++;
		count++;
	}
	if (check == 1)
		return (count);
	else
		return (0);
}

int calc(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (0);
}

int solve_rpn(t_rpn *tab, int size)
{
	int i = 0;

	while (size > 1)
	{
		i = 0;
		while (!tab[i].op)
			i++;
		tab[i - 2].nb = calc(tab[i - 2].nb, tab[i - 1].nb, tab[i].op);
		while (i < size)
		{
			tab[i - 1] = tab[i + 1];
			i++;
		}
		size -= 2;
	}
	return (tab[0].nb);
}

int	rpn_calc(char *str, int size)
{
	int i;
	int j;
	t_rpn *tab;

	tab = malloc(sizeof(t_rpn) * size);
	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (i < size)
	{
		if (is_ope(str, &j))
		{
			tab[i].nb = -1;
			tab[i].op = str[j - 1];
			i++;
		}
		else 
		{
			tab[i].op = 0;
			tab[i].nb = atoi(str + j);
			i++;
		}
		while (str[j] != ' ' && str[j])
			j++;
		while (str[j] == ' ')
			j++;
	}
/*	i = 0;
	while (i < size)
	{
		printf("%c       %d\n", tab[i].op, tab[i].nb);
		i++;
	}*/
	return (solve_rpn(tab, size));
}

int main(int argc, char **argv)
{
	int size = 0;
	if (argc == 2)
	{
		if ((size = valid_arg(argv[1])))
			printf("%d\n", rpn_calc(argv[1], size));
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
}
