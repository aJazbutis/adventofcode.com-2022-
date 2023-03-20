#include <iostream>
#include <fstream>
#include <queue>

int	main(int argc, char **argv)	{
	if (argc != 2)
		return 0;
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
		return 0;
	std::queue<std::string>	q;
	int	x = 1, cycle = 1;
	std::string	line;
	while(std::getline(ifs, line))	{
		if (!line.empty())
			q.push(line);
	}
	ifs.close();
	if (q.empty())
		return 0;
	while (cycle)	{
		if (!q.empty())	{
			line = q.front();
			q.pop();
			if (line == "noop")	{
				if (abs((cycle - 1) % 40 - x) < 2)
					std::cout << '#';
				else
					std::cout << '.';
				if (!(cycle % 40))
					std::cout << std::endl;
				cycle++;
			}
			else	{
				for (int i = 0; i < 2; i++)	{
					if (abs((cycle - 1) % 40 - x) < 2)
						std::cout << '#';
					else
						std::cout << '.';
					if (!(cycle % 40))
						std::cout << std::endl;
					cycle++;
				}
				x += std::stoi(line.substr(4));
			}	
		}
		else
			break;
	}
	return 0;
}
