
#include <iostream>
#include <fstream>

int	main(int argc, char **argv)	{
	std::ifstream	ifs(argv[1]);
	int res = 0;
	int a, b, c, d;

	while (ifs >> a >> b >> c >> d)	{
		if (((a >= c && a <= d) || (b >= c && b <= d)) ||
			((c >= a && c <= b) || (d >= a && d <= b)))
			res++;
	}
	ifs.close();
	std::cout << res << std::endl;
	return (0);
}
