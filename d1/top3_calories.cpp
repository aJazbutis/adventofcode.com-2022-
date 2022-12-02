#include <iostream>
#include <fstream>
#include <vector>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	std::vector<int> w;
	std::vector<int>::iterator it;
	int res = 0;
  	std::string::size_type sz;   // alias of size_t
	while (std::getline(ifs, line))	{
		if (!line.empty())	{
  			res += std::stoi (line, &sz);
			continue ;
		}
		w.push_back(res);
		res = 0;
	}
	res = 0;
	for (int i = 0; i < 3; i++)	{
		it = max_element(w.begin(), w.end());
		res += *it;
		w.erase(it);
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
