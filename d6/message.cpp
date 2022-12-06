#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	int res = 14;
	std::getline(ifs, line);
	for (int i = 0; i < line.length() - 14; i++)	{
		std::string msg = line.substr(i, 14);
		int j = 0;
		while(j < 14 && (msg.find_first_of(msg[j]) == msg.find_last_of(msg[j])))
			j++;
		if (j == 14)
			break ;
		res++;
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
