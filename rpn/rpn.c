#include <stdio.h>
#include <stdlib.h>

void 	rpn(char *tab)
{
	int i;
	int f1;
	int f2;
	char sign;
	int nb;
	char tmp[50];
	int u;

	i = 0;
	f1 = 0;
	f2 = 0;
	sign = '0';
	nb = 0;
	u = 0;
	while (tab[i])
	{	
		u = 0;
		while (tab[i] <= '9' && tab[i] >= '0')
		{	
			tmp[u] = tab[i];
			i++;
			u++;
		}
		if (f1 == 0)
			f1 = atoi(tmp);
		f2 = atoi(tmp);
		if (tab[i] == '*' || tab[i] == '/' || tab[i] == '%' || tab[i] == '-' || tab[i] == '+')
			sign = tab[i];
		if (f1 != '0' && f2 != '0' && sign != '0')
		{
			if (sign == '+')
			{
				nb = f1 + f2;
				f1 = 0;
				f2 = 0;
			}
			if (sign == '-')
			{
				nb = f1 - f2;
				f1 = 0;
				f2 = 0;
			}
			if (sign == '/')
			{
				nb = f1 / f2;
				f1 = 0;
				f2 = 0;
			}
			if (sign == '*')
			{
				nb = f1 * f2;
				f1 = 0;
				f2 = 0;
			}
			if (sign == '%')
			{
				nb = f1 % f2;
				f1 = 0;
				f2 = 0;
			}
			sign = '0';
			f1 = nb;
		}
		i++;
	}
	printf("%d\n", nb);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n");
	}
	else
		rpn(argv[1]);
	return (0);
}