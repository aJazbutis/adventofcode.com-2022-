#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int res = 0;
	while (std::getline(ifs, line))	{
		std::string line2;
		std::string line3;
		std::getline(ifs, line2);
		std::getline(ifs, line3);
		int i = -1;
		while (line[++i])	{
			if (line2.find_first_of(line[i]) != std::string::npos &&
				line3.find_first_of(line[i]) != std::string::npos)	{
				if (line[i] > 96)
					res += line[i] - 96;
				else
					res += line[i] - 38;
				break ;
			}
		}
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
