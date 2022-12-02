#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int res = 0;
	while (std::getline(ifs, line))	{

			std::cout << line << std::endl;
		switch (line[2])	{
			case (89):
				res += 2;
				switch (line[0])	{
					case (65):
						res += 6;
						break ;
					case (66):
						res += 3;
						break ;
				}
				break ;
			case (88):
				res += 1;
				switch (line[0])	{
					case (65):
						res += 3;
						break ;
					case (67):
						res += 6;
				}
				break ;
			case (90):
				res += 3;
				switch (line[0])	{
					case (66):
						res += 6;
						break ;
					case (67):
						res += 3;
				}
		}
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
