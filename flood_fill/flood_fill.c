#include <stdio.h>
#include <stdlib.h>
typedef struct s_point
{
    int x;
    int y;
}               t_point;

void    flood(char **tab, t_point size, char c, int y, int x)
{
    if (x < 0 || y < 0 || x >= size.x || y >= size.y)
        return ;
    if (tab[y][x] == 'F' || c != tab[y][x])
        return ;
    tab[y][x] = 'F';
    flood(tab, size, c, y + 1, x);
    flood(tab, size, c, y - 1, x);
    flood(tab, size, c, y, x + 1);
    flood(tab, size, c, y, x - 1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char c;
    c = tab[begin.y][begin.x];
    flood(tab, size, c, begin.y, begin.x);
}

char **make_area(char **zone, int _x, int _y)
{
    char **area;
    area = (char **)malloc(sizeof(char *) * _y);
    for (int i = 0; i < _y; ++i)
    {
        area[i] = (char *)malloc(sizeof(char) * _x);
        for (int j = 0; j < _x; ++j)
            area[i][j] = zone[i][2 * j];
    }
    return (area);
}
int main(void)
{
    char *zone[] = {
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 0 0 0 0 1",
        "1 1 0 0 0 0 0 0",
    };
    t_point size  = {8, 5};
    t_point begin = {1, 1};
    char **area = make_area(zone, size.x, size.y);
    flood_fill(area, size, begin);
    for (int y = 0; y < size.y; y++)
    {
        for (int x = 0; x < size.x; x++)
        {
            if (x != 0)
                printf(" ");
            printf("%c", area[y][x]);
        }
        printf("\n");
    }
    free(area);
    return (0);
}