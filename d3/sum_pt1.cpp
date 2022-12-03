#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int res = 0;
	while (std::getline(ifs, line))	{
			int l = line.length() / 2;
			std::string pt2 = line.substr(l, l);
			line = line.substr(0, l);
			int i = -1;
			while (line[++i])	{
				if (pt2.find_first_of(line[i]) != std::string::npos)	{
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
