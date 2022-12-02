#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int	max = -1;
	int res = 0;
  	std::string::size_type sz;   // alias of size_t
	while (std::getline(ifs, line))	{
		if (!line.empty())	{
  			res += std::stoi (line, &sz);
			continue ;
		}
		if (max < res)
			max = res;
		res = 0;
	}
	ifs.close();
	std::cout << max << std::endl;
	return (0);
}
