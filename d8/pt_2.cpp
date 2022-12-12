#include <iostream>
#include <fstream>
#include <vector>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	std::vector<std::string> map;
	while (std::getline(ifs, line))
		map.push_back(line);
	ifs.close();

	int l = map[0].length();
	int h = map.size();
	int i = 0;
	int j;
	int max = 0;
	int count = 1;
	while (++i < h - 1)	{
		int tree = 0;
		int res = 1;
		while (++tree < l - 1)	{
			j = tree;
			count = 1;
			res = 1;
			while (--j > 0)	{
				if (map[i][tree] <= map[i][j])
					break ;
				count++;
			}
			res = res * count;
			j = tree;
			count = 1;
			while (++j < l - 1)	{
				if (map[i][tree] <= map[i][j])	
					break ;
				count++;
			}
			res = res * count;
			j = i;
			count = 1;
			while (--j > 0)	{
				if (map[i][tree] <= map[j][tree])
					break ;
				count++;
			}
			res = res * count; 
			j = i;
			count = 1;
			while (++j < h - 1)	{
				if (map[i][tree] <= map[j][tree])
					break ;
				count++;
			}
			res = res * count;
			if (max < res)
				max = res;
		}		
	}
	std::cout << max << std::endl;
	return (0);
}
