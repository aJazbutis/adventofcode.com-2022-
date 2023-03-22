#include "monkey.hpp"
#include <fstream>
#include <sstream>
#include <set>

int main(int argc, char **argv)	{
	if (argc != 2)
		return 0;
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
		return 0;
	std::vector<Monkey *>	m;
	std::string	line;
	std::string	items;
	Monkey	*monkey;
	while (std::getline(ifs, line))	{
		std::string	s;
		if (line.empty())
			continue ;
		if (!line.compare(0, 6, "Monkey"))
			continue ;
		s = "Starting";
		if (line.find(s) != std::string::npos)	{
			items = line.substr(line.find_first_of(DIGITS));
			continue ;
		}
		s = "Operation";
		if (line.find(s) != std::string::npos)	{
			std::size_t	f = line.find_first_of("+*");
			if (line[f] == '+')	{
				monkey = new mSum();
				monkey->setX(std::stoi(line.substr(f + 1)));
			}
			else if (line.find_first_of(DIGITS) == std::string::npos)	{
				monkey = new mPow();
			}
			else	{
				monkey = new mMlt();
				monkey->setX(std::stoi(line.substr(f + 1)));
			}
			int i;
			char comma;
			std::stringstream ss(items);
			while (ss >> i)	{
				monkey->catchItem(i);
				ss >> comma;
			}
		}
		s = "Test";
		if (line.find(s) != std::string::npos)	{
			monkey->setTest(std::stoi(line.substr(line.find_first_of(DIGITS))));
		}
		s = "true";
		if (line.find(s) != std::string::npos)	{
			monkey->setIdx1(std::stoi(line.substr(line.find_first_of(DIGITS))));
		}	
		s = "false";
		if (line.find(s) != std::string::npos)	{
			monkey->setIdx2(std::stoi(line.substr(line.find_first_of(DIGITS))));
			m.push_back(monkey);
		}
	}
	for (int i = 0; i < m.size(); i++)	{
		m[i]->setMates(m);
	}
	for (int i = 0; i < 20; i++)	{
		for (std::vector<Monkey *>::iterator it = m.begin(); it < m.end(); it++)	{
			(*it)->inspectItems();
		}
	}
	std::set<int>	s;
	for (std::vector<Monkey *>::iterator it = m.begin(); it < m.end(); it++)	{
			std::cout << (*it)->getInspected() << std::endl;
			s.insert((*it)->getInspected());
	}	
	for (int i = 0; i < m.size(); i++)	{
		delete m[i];
	}
	std::set<int>::reverse_iterator rt = s.rbegin();
	std::cout << (*rt * *(++rt)) << std::endl;
	return 0;
}
