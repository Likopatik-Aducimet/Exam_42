#include <stdlib.h>
#include <stdio.h>

static size_t digi_count(int nb, int base)
{
    int i;

    i = 0;
    while (nb)
    {
        nb /= base;
        i++;
    }
    return (i);
}

char *ft_itoa_base(int nb, int base)
{
    int i;
    int taille;
    char *ret;
    char tab_base[17] = "0123456789ABCDEF";
    int sign;

    sign = 0;
    if (base < 2 || base > 16)
        return (0);
    if (nb == -2147483648 && base == 10)
        return ("-2147483648");
    if (nb < 0)
    {
        nb = -nb;
        sign = 1;
    }
    taille = digi_count(nb, base);
    if (sign)
        taille += 1;
    ret = (char *)malloc(sizeof(char) * (taille + 1));
    i = 1;
    if (sign)
        ret[0] = '-';
    while (nb != 0)
    {
        ret[taille - i++] = tab_base[nb % base];
        nb /= base;
    }
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
