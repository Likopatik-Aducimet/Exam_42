#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct 	t_point
{
	int x;
	int y;
}				s_point;

void putcarac(char c)
{
	write (1, &c, 1);
}

void 	putstr(char *tab)
{
	int i = 0;

	while (tab[i])
	{
		putcarac(tab[i]);
		i++;
	}
}

int 	len_str(char *tab)
{
	int i = 0;
	while (tab[i])
		i++;
	return (i);
}

int 	pion(struct t_point max, char **tab, int y, int x)
{	
	if ((x - 1 > 0 &&  max.x >= x + 1) && (y - 1 > 0 &&  max.y >= y + 1))
	{
		if (tab[y - 1][x - 1] == 'K' || tab[y - 1][x + 1] == 'K')
			return (1);
		else
			return (0);
	}
	return(0);
}

int 	tour(struct t_point max, char **tab, int y, int x)
{	
	int i = x + 1;
	int j = y + 1;
	int check = 0;


	while (j < max.y && check == 0)
	{	
		if (tab[j][x] == 'P' || tab[j][x] == 'R' || tab[j][x] == 'B' || tab[j][x] == 'Q')
			break;
		if (tab[j][x] == 'K')
			check = 1;
		j++; 
	}
	j = y - 1;
	while (j >= 0 && check == 0)
	{	
		if (tab[j][x] == 'P' || tab[j][x] == 'R' || tab[j][x] == 'B' || tab[j][x] == 'Q')
			break;
		if (tab[j][x] == 'K')
			check = 1;
		j--;
	}
	while (i < max.x && check == 0)
	{	
		if (tab[y][i] == 'P' || tab[y][i] == 'R' || tab[y][i] == 'B' || tab[y][i] == 'Q')
			break;
		if (tab[y][i] == 'K')
		{
			check = 1;
		}
		i++;
	}
	i = x - 1;
	while (i >= 0 && check == 0)
	{	
		if (tab[y][i] == 'P' || tab[y][i] == 'R' || tab[y][i] == 'B' || tab[y][i] == 'Q')
			break;
		if (tab[y][i] == 'K')
		{
			check = 1;
		}
		i--;
	}
	if (check == 1)
		return (1);
	else 
		return (0);
}

int 	fou(struct t_point max, char **tab, int y, int x)
{	
	int i;
	int j;
	int check = 0;
	i = x;
	j = y;
	while (j >= 0 && j <= max.y && i >= 0 && i <= max.x)
	{	
		if (tab[y][i] == 'P' || tab[y][i] == 'R' || tab[y][i] == 'B' || tab[y][i] == 'Q')
			break;
		if (tab[j][i] == 'K')
		{
			check = 1;
			return(check);
		}
		j--;
		i--;
	}
	i = x;
	j = y;
	while (j > 0 && j <= max.y && i >= 0 && i <= max.x)
	{	
		if (tab[y][i] == 'P' || tab[y][i] == 'R' || tab[y][i] == 'B' || tab[y][i] == 'Q')
			break;
		if (tab[j][i] == 'K')
		{
			check = 1;
			return(check);
		}
		j--;
		i++;
	}
	i = x;
	j = y;
	while (j > 0 && j <= max.y && i >= 0 && i <= max.x)
	{	
		if (tab[y][i] == 'P' || tab[y][i] == 'R' || tab[y][i] == 'B' || tab[y][i] == 'Q')
			break;
		if (tab[j][i] == 'K')
		{
			check = 1;
			return(check);
		}
		j++;
		i--;
	}
		i = x;
	j = y;
	while (j > 0 && j <= max.y && i >= 0 && i <= max.x)
	{	
		if (tab[y][i] == 'P' || tab[y][i] == 'R' || tab[y][i] == 'B' || tab[y][i] == 'Q')
			break;
		if (tab[j][i] == 'K')
		{
			check = 1;
			return(check);
		}
		j++;
		i++;
	}
	return (0);
}

void	check_mate(char **argv, int argc) 	
{
	int y = 1;
	char **tab = NULL;
	int len = 0;
	int x = 0;
	int check = 0;
	struct t_point max;

	tab = malloc(sizeof(char *) * argc);
	len = len_str(argv[1]);
	max.x = len;
	max.y = argc - 1;
	while (y < argc)
	{
		tab[y] = malloc(sizeof(char) * len);
		y++;
	}
	y = 1;
	while (y < argc)
	{	
		tab[x] = argv[y];	
		y++;
		x++;
	}
	y = 0;
	while (y < argc && check == 0)
	{
		x = 0;
		while (tab[y][x] && check == 0)
		{	
			if (tab[y][x] == 'P')
				check = pion(max,tab, y, x);
			else if (tab[y][x] == 'R')
			{
				check = tour(max, tab, y, x);
			}
			else if (tab[y][x] == 'B')
				check = fou(max, tab, y, x);
			else if (tab[y][x] == 'Q')
			{	
				if (check == 0)
					check = fou(max, tab, y, x);
				if (check == 0)
					check = tour(max, tab, y, x);
			}
			x++;
		}
		y++;
	}
	if (check == 1)
		putstr("Success\n");
	else
		putstr("Fail\n");
}

int		main (int argc, char **argv)
{	
	if (argc < 2)
	{
		putcarac('\n');
	}
	else
		check_mate(argv, argc);
}