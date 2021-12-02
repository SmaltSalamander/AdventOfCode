#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	depth;
	int	horpos;
	int	fd;
	int	aim;
	char	*str;
	int	val;

	horpos = 0;
	depth = 0;
	aim = 0;
	fd = open("./input.txt", O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_putstr_fd(str, 1);
		if (ft_strncmp(str, "forward ", 7) == 0)
		{
			val = ft_atoi(str + 7);
			horpos += val;
			depth += aim * val;
		}
		else if (ft_strncmp(str, "down ", 4) == 0)
			aim += ft_atoi(str + 4);
		else if (ft_strncmp(str, "up ", 2) == 0)
			aim -= ft_atoi(str + 2);
		ft_printf("\n%d\n%d\n", horpos, depth);
		free(str);
	}
	if (ft_strncmp(str, "forward ", 7) == 0)
	{
		val = ft_atoi(str + 7);
		horpos += val;
		depth += aim * val;
	}
	else if (ft_strncmp(str, "down ", 4) == 0)
		aim += ft_atoi(str + 4);
	else if (ft_strncmp(str, "up ", 2) == 0)
		aim -= ft_atoi(str + 2);
	free(str);
	ft_printf("%d\n%d\n%d\n", horpos, depth, horpos * depth);
	return (horpos * depth);
}
