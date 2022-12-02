#include <fstream>
#include <iostream>

int	ft_atoi(const char *nptr);

int main(void)
{
	std::fstream ofs;
	std::string		line;
	int				count = 0;
	int				maxcount[3] = {0, 0, 0};

	ofs.open("./input.txt");
	while (std::getline(ofs, line))
	{
		if (line == "")
		{
			if (maxcount[2] < count)
			{
				maxcount[0] = maxcount[1];
				maxcount[1] = maxcount[2];
				maxcount[2] = count;
			}
			else if (maxcount[1] < count)
			{
				maxcount[0] = maxcount[1];
				maxcount[1] = count;
			}
			else if (maxcount[0] < count)
				maxcount[0] = count;
			count = 0;
		}
		else
			count += ft_atoi(line.c_str());
	}
	std::cout << maxcount[2] + maxcount[1] + maxcount[0] << std::endl;

	return (0);
}