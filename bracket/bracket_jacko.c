#include <unistd.h>

int     is_b(char a, char  b)
{
    return((a == '[' && b == ']' ) || (a == '{' && b == '}' ) || (a == '(' && b == ')'));
}

int     bracket(char *str)
{
    int i = -1;
    int j = 0;
    char tab[4096] = {0};
    while (str[++i])
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
            tab[++j] = str[i];
        if (str[i] == ']' || str[i] == '}' || str[i] == ')')
            if (!is_b(tab[j--], str[i]))
                return (0);
    }
    return !j;
}

int     main(int ac, char **av)
{
    int i = 0;
    if (ac < 2)
        return(write(1, "\n", 1));
    while (++i < ac)
    {
        if (bracket(av[i]))
            write(1, "Ok\n", 3);
        else
            write(1, "Error\n", 6);
    }
    return (0);
}