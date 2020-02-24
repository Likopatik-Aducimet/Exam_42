#include <stdlib.h>
#include <stdio.h>

size_t  count_digit(int value, int base)
{
    int i = 0;

    while (value)
    {   
        value /= base;
        i++;
    }
    return (i);
}

char *ft_itoa_base(int value, int base)
{
    int i = 0;
    int sign = 0;
    int taille = 0;
    char *ret;
    char tab_char[17] = "0123456789ABCDEF";

    if (base < 2 || base > 10)
        return (0);
    if (value == 0)
        return("0");
    if (value == -2147483648 && base == 10)
        return ("-2147483648");
    if (value < 0 && base == 10)
        sign = 1;
    if (value < 0)
        value = -value;
    taille = count_digit(value, base);
    if (sign)
        taille += 1;
    ret = malloc(sizeof(char) * taille + 1);
    if (sign)
        ret[0] = '-';
    i = 1;
    while (value)
    {
        ret[taille - i++] = tab_char[value % base];
        value /= base; 
    }
    ret[taille] = '\0';
    return (ret);
}

int main(int argc, char **argv)
{
    if (argc == 3)
		printf("ret = %s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return (0);
}