#include <unistd.h>
typedef struct		s_map
{
	int h;
	int w;
}					t_map;

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	t_map	size;

	if (argc > 1)
	{
		size.h = argc - 1;
		size.w = argc - 1;
		while (argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				if (argv[j][i] == 'P')
				{
					if (i + 1 < size.w && j - 1 >= 0)
						if (argv[j - 1][i + 1] == 'K')
							return (write(1, "Success\n", 8));
					if (i - 1 >= 0 && j - 1 >= 0)
						if (argv[j - 1][i - 1] == 'K')
							return (write(1, "Success\n", 8));
				}
				y = j;
				x = i;
				if (argv[j][i] == 'R' || argv[j][i] == 'Q')
				{
					while (--y >= 0)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
					y = j;
					while (++y <= size.h)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
					y = j;
					while (--x >= 0)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
					x = i;
					while (++x <= size.w)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
				}
				y = j;
				x = i;
				if (argv[j][i] == 'B' || argv[j][i] == 'Q')
				{
					while (--y >= 0 && --x >= 0)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
					y = j;
					x = i;
					while (--y >= 0 && ++x <= size.w)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
					y = j;
					x = i;
					while (++y <= size.h && ++x <= size.w)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
					y = j;
					x = i;
					while (++y <= size.h && --x >= 0)
					{
						if (argv[y][x] == 'R' || argv[y][x] == 'P' || argv[y][x] == 'Q' || argv[y][x] == 'B')
							break ;
						else if (argv[y][x] == 'K')
							return (write(1, "Success\n", 8));
					}
				}
				i++;
			}
			j++;
		}
		return (write(1, "Fail\n", 5));
	}
	return (write(1, "\n", 1));
}
