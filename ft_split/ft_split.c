#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ft_count_word(char *str)
{
    int nb;
    int i;

    i = 0;
    nb = 0;
    while (str[i])
    {
        if ((str[i] > 33 && str[i] < 126) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            nb++;
        i++;
    }
    return (nb);
}
char *assign_word(char *str, int i)
{   
    int len_word;
    char *tmp;
    int j;

    j = i;
    len_word = 0;
    while (str[j] && (str[j] != ' ' || str[j] != '\0'))
    {   
        printf("salut\n");
        len_word++;
        j++;
    }
    tmp = malloc(sizeof(char) * len_word + 1);
    printf("\n");
    return(tmp);
}

char **ft_split(char *str)
{   
    int nb_word;
    char **tab;
    int i;
    int len_word;
    int word;

    i = 0;
    word = 0;
    tab = NULL;
    nb_word = ft_count_word(str);
    tab = malloc(sizeof(char *) * nb_word);
    while (str[i])
    {   
        len_word = 0;
        if (str[i] > 33 && str[i] < 126)
        {   
            tab[word] = assign_word(str, i);
            while (str[i] != ' ' || str[i] != '\0')
            {   
                tab[word][len_word] = str[i];
                i++;
                len_word++;
            }
            tab[word] = malloc(sizeof(char) * len_word + 1);

            word++;
        } 
        i++;
    }
    return (tab);
}

int main()
{
    char **tab;
    char *tmp;
    int i;

    i = 0;
    tmp = strdup("SALUT LES S");
    tab = ft_split(tmp);
    while (tab[i])
    {
        printf("tab[i] = %s", tab[i]);
        i++;
    }
    return (0);
}