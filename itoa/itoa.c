#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return(i);
}

char    *ft_strrev(char *str)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = ft_strlen(str);
    while(i < j)
    {
        j--;
        tmp = str[i];
        str[i] = str[j];
		str[j] = tmp;
        i++;

    }
    return(str);
}

char	*ft_itoa(int nbr)
{
    char *tmp;
    int neg;
    int i;

    i = 0;
    neg = 0;
    tmp = malloc(sizeof(char) * 12);
    if (nbr == 0)
        return ("0");
    if (nbr < 0)
    {
        neg = 1;
        nbr *= -1;
    }
    if (nbr == -2147483648)
        return ("-2147483648");
    while (nbr)
    {
        tmp[i] = (nbr % 10) + '0';
        nbr /= 10;
        i++;
    }
    if (neg)
    {
        tmp[i] = '-';
    }
    return (ft_strrev(tmp));
}


int main()
{
    int tab[4];
    int i;

    i = 0;
    tab[0] = -2147483648;
    tab[1] = 2147483647;
    tab[2] = 420;
    tab[3] = 0;
    while (i < 4)
    {   
        printf("RF = %d\n", tab[i]);
        printf("MF = %s\n", ft_itoa(tab[i]));
        printf("\n");
        i++;
    }
}