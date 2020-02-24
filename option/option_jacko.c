#include <unistd.h>

int     is_alpha(char a)
{
    return(a >= 'a' && a <= 'z');
}

int     main(int ac, char **av)
{
    int i = 0;
    int j;
    int tab[32] = {0};
    if (ac < 2)
        return(write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
    while (av[++i])
    {
        j = 0;
        while (av[i][++j])
        {
            if (av[i][0] != '-')
                return(write(1, "Invalid option\n", 15));
            else if (av[i][j] == 'h')
                return(write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
            else if (!is_alpha(av[i][j]))
                return(write(1, "Invalid option\n", 15));
            else
                tab['z' - av[i][j] + 6] = 1;
        }
    }
    i = 0;
    while (i < 32)
    {
        tab[i] += 48;
        write(1, &tab[i++], 1);
        if (i % 8 == 0)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
    return (0);
}