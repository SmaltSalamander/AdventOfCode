#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

int	sum(int num[3])
{
	int	counter;
	int	result;

	counter = 0;
	result = 0;
	while (counter < 3)
	{
		result += num[counter];
		counter++;
	}
	return (result);
}

void	shift_down(int **num)
{
	int	counter;

	counter = 0;
	while (counter < 3)
	{
		(*num)[counter] = (*num)[counter + 1];
		counter++;
	}
	return ;
}

int	main(void)
{
	int		fd;
	int		*num;
	char	*str;
	int		counter;

	counter = 0;
	fd = open("./input.txt", O_RDONLY);
	num = ft_calloc(sizeof(int), 4);
	while (get_next_line(fd, &str) && counter < 4)
	{
		num[counter++] = ft_atoi(str);
		free(str);
	}
	counter = 0;
	if (num[3] > num[0])
		counter++;
	while (get_next_line(fd, &str))
	{
		shift_down(&num);
		num[3] = ft_atoi(str);
		free(str);
		if (num[3] > num[0])
			counter++;
	}
	ft_putnbr_fd(counter, 1);
	return (counter);
}
