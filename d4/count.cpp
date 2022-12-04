#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	int res = 0;
	int a, b, c, d;

	while (ifs >> a >> b >> c >> d)	{
		if ((a <= c && b >= d) || ( a >= c && b <= d))
			res++;
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
