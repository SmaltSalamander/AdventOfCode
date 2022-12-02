#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	values[12];
	char	*gamma;
	char	*epsilon;
	int	counter;
	int		fd;
	char	*str;
	int		result;

	counter = 0;
	ft_bzero(values, sizeof(int) * 12);
	fd = open("./input.txt", O_RDONLY);
	while (get_next_line(fd, &str))
	{
		while (counter < 12)
		{
			if (str[counter] == '0')
				values[counter]++;
			if (str[counter] == '1')
				values[counter]--;
			counter++;
		}
		free(str);
		counter = 0;
	}
	gamma = malloc(12);
	epsilon = malloc(12);
	while (counter < 12)
	{
		if (values[counter] > 0)
		{
			gamma[counter] = '1';
			epsilon[counter] = '0';
		}
		else
		{
			gamma[counter] = '0';
			epsilon[counter] = '1';
		}
		counter++;
	}
	ft_putstr_fd(gamma, 1);
	write(1, "\n", 1);
	ft_putstr_fd(epsilon, 1);
	return (0);
}
