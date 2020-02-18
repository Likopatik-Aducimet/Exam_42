#include <stdio.h>
#include <stdlib.h>

static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	sign = 0;
	if (base == 10 && value < 0)
		sign = 1;
	if (value < 0)
		value = -value;
	if (value == 0)
		return ("0");
	tab_base = (char *)malloc(sizeof(char) * 17);
	tab_base = "0123456789ABCDEF";
	taille = digit_count(value, base);
	taille += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}

int main(int argc, char **argv)
{
    // int tab[4];
    // int i;

    // i = 0;
    // tab[0] = -2147483648;
    // tab[1] = 2147483647;
    // tab[2] = 420;
    // tab[3] = 0;
    // while (i < 4)
    // {   
    //     printf("RF = %d\n", tab[i]);
    //     printf("MF = %s\n", ft_itoa_base(tab[i], 4));
    //     printf("\n");
    //     i++;
    // }
	if (argc == 3)
		printf("ret = %s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return (0);
}