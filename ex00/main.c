#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	int num[2];
	char	*str;
	int	counter;

	counter = 1;
	ft_bzero(num, sizeof(int) * 2);
	fd = open("./input.txt", O_RDONLY);
	get_next_line(fd, &str);
	num[0] = ft_atoi(str);
	free(str);
	while (get_next_line(fd, &str))
	{
		num[1] = ft_atoi(str);
		if (num[0] < num[1])
			counter++;
		num[0] = num[1];
		free(str);
	}
	ft_putnbr_fd(counter, 1);
	return (counter);
}
