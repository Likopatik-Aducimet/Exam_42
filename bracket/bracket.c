#include <stdio.h>
#include <unistd.h>

int         is_b(char a, char b)
{
    return ((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')'));
}

int        bracket(char *tab)
{
    int i = -1;
    int j = 0;
    char str[4096] = {0};

    while (tab[++i])
    {
        if (tab[i] == '[' || tab[i] == '{' || tab[i] == '(')
            str[++j] = tab[i];
        if (tab[i] == ']' || tab[i] == '}' || tab[i] == ')')
            if (!(is_b(str[j--], tab[i])))
                return (0);
    }
    return !j;
}

int     main(int argc, char **argv)
{   
    int i = 0;
    if (argc < 2)
        printf("\n");
    else
    {
        while (++i < argc)
        {   
            if (bracket(argv[i]))
                write(1, "Ok\n", 3);
            else
                write(1, "Error\n", 6);
        }
    }
}