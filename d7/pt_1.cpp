#include <vector>
#include <queue>
#include <iostream>
#include <iostream>
#include <fstream>
#include <cctype>

class node	{
	public:
	int			data;
	std::string name;
	std::vector<node>child;
	node	*up;
		node(std::string name, node *up): data(0), name(name), up(up)	{};
		~node(void){};
		node	&operator=(node const &rhs) {
			data = rhs.data;
			name = rhs.name;
			up = rhs.up;
			child = rhs.child;
			return (*this);
		};
};

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	std::string		line;
	node	root = node("root", NULL);
	node	*t = &root;


	std::vector<node>::iterator it;
	std::getline(ifs, line);
	while (std::getline(ifs, line))	{
		if (line == "$ ls")
			continue ;
		if (!line.compare(0, 3, "dir"))	{
			t->child.push_back(node(line.substr(4), t));
		}
		else if (isdigit(line[0])) {
			t->data += std::stoi(line);
		}
		else if (!line.compare(0, 4, "$ cd"))	{
			line = line.substr(5);
			if (!line.compare(".."))	{
//				t->child.push_back(node("end", t)); 
				if (t->up)	{
					t->up->data += t->data;
					t = t->up;
				}
				while (std::getline(ifs, line) && !line.compare(0, 4, "$ cd"))	{
					line = line.substr(5);
					if (!line.compare(".."))	{
						if (t->up) {
							t->up->data += t->data;
							t = t->up;
						}
						continue ;
					}
					else	{
						for (it = t->child.begin(); it < t->child.end(); it++)	{
							if ((*it).name.compare(line) == 0)	{
								t = &(*it);
								break ;
							}
						}
					}
				}
			}
			else {
				for (it = t->child.begin(); it < t->child.end(); it++)	{
					if ((*it).name.compare(line) == 0)	{
						t = &(*it);
						break ;
					}
				}
			}
		}
	}

	ifs.close();
	t = &root;
	int sum = 0;
	std::queue<node> q;
	q.push(root);
	while (!q.empty())	{
		int n = q.size();
		while (n > 0)	{
			*t = q.front();
			q.pop();
			if (t->data <= 100000)
				sum +=t->data;
			for (int i = 0; i < t->child.size(); i++)	{
				q.push(t->child[i]);
			}
			n--;
		}
	}
	std::cout << sum << std::endl;
	return (0);
}
