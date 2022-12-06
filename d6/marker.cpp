#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int res = 4;
	std::getline(ifs, line);
	for (int i = 0; i < line.length() - 4; i++)	{
		std::string marker = line.substr(i, 4);
		int j = 0;
		while(j < 4 && (marker.find_first_of(marker[j]) == marker.find_last_of(marker[j])))
			j++;
		if (j == 4)
			break ;
		res++;
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
