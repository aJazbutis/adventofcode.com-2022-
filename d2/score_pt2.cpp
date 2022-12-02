
#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int res = 0;
	while (std::getline(ifs, line))	{
		switch (line[2])	{
			case (88):
				switch (line[0])	{
					case (65):
						res += 3;
						break ;
					case (66):
						res += 1;
						break ;
					case (67):
						res += 2;
				}
				break ;
			case (89):
				res += 3;
				switch (line[0])	{
					case (65):
						res += 1;
						break ;
					case (66):
						res += 2;
						break ;
					case (67):
						res += 3;
				}
				break ;
			case (90):
				res += 6;
				switch (line[0])	{
					case (65):
						res += 2;
						break ;
					case (66):
						res += 3;
						break ;
					case (67):
						res += 1;
				}
		}
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
