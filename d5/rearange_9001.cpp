#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <string>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::stack<char> stack[9];
{
	std::string		line[8];
	for (int i = 7; i > -1; i--)
		std::getline(ifs, line[i]);
	for (int i = 0; i < 8; i++)	{
		const char *s = line[i].c_str();
		int idx = 0;
		for (int j = 1; j < line[i].length(); j += 4)	{
			if (isalpha(s[j]))	
				stack[idx].push(s[j]);
			idx++;
		}
	}
}	
	std::string line;
	std::getline(ifs, line);
  	std::string::size_type sz;
	while (std::getline(ifs, line))	{
		int moves, from, to;
		if (!line.empty())	{
			line = line.substr(5);
			moves = std::stoi(line, &sz);
			line = line.substr(sz + 5); 
			from = std::stoi(line, &sz) - 1;
			line = line.substr(sz + 3);
			to = std::stoi(line, &sz) - 1; 
			std::stack<char> crane;
			while (moves--)	{
				crane.push(stack[from].top());
				stack[from].pop();
			}		
			while (crane.size())	{
				stack[to].push(crane.top());
				crane.pop();
			}
		}
	}
	for (int i = 0; i < 9; i++)	{
	        std::cout << stack[i].top();
	}
		std::cout << std::endl;
	ifs.close();
	return (0);
}
