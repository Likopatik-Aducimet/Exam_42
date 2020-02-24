#include <unistd.h>
#include <stdio.h>

int is_b(char a, char b)
{
    return((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']'));
}

int     bracket(char *tab)
{
    int i = -1;
    int j = 0;
    char str[4096] = {0};

    while (tab[++i])
    {
        if (tab[i] == '(' || tab[i] == '{' || tab[i] == '[')
            str[++j] = tab[i];
         if (tab[i] == ')' || tab[i] == '}' || tab[i] == ']')
            if (!(is_b(str[j--], tab[i])))
                return(0);
    }
    return(!j);
}

int     main(int argc, char **argv)
{
    int i = 1;
    if (argc < 2)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            if (bracket(argv[i]))
                (write(1, "OK\n", 3));
            else
                (write(1, "Error\n", 6));
            i++;
        }

    }
}