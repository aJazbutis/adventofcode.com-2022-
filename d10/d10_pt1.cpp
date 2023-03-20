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
	int sum = 0;
	if (q.empty())
		return 0;
	while (cycle)	{
		if (!q.empty())	{
			line = q.front();
			q.pop();
			if (line == "noop")	{
				if (cycle % 40 == 20)	{
					sum += x * cycle;
				}
				cycle++;
			}
			else	{
				for (int i = 0; i < 2; i++)	{
					if (cycle % 40 == 20)	{
						sum += x * cycle;
					}
					cycle++;
				}
				x += std::stoi(line.substr(4));
			}	
		}
		else
			break;
	}
	std::cout << sum << std::endl;
	return 0;
}
