/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:28:30 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/08/19 20:29:02 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Substitutor.hpp"

int	main(int argc, char **argv)	{
	if (argc != 4)	{
		std::cout << "wrong argument count" << std::endl;
		std::cout << "./ex04 filename s1 s2" << std::endl;
		return (0);
	}

	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())	{
		std::cout << "unable to open " << argv[1] << std::endl;
		return (0);
	}

	std::string		line = argv[1];
	std::ofstream	ofs(line + ".replace", std::ios::out | std::ios::trunc);
	if (!ofs.is_open())	{
		ifs.close();
		std::cout << "unable to open/create output file" << std::endl;
		return (0);
	}

	line = argv[2];
	if (!line.empty())	{
		Substitutor		dasSubstitutor(argv[2], argv[3]);
	
		while (std::getline(ifs, line))	{
			line = dasSubstitutor.substitute(line);
			ofs << line << std::endl;
		}
	}
	else
		std::cout << "Due to obvious reasons substitution will not be executed" << std::endl;
	ifs.close();
	ofs.close();
	return (0);
}

/*std::string	ft_replace(std::string line, std::string s1, std::string s2)	{
	std::size_t	found;
	std::string	ret = "";
	
	found = line.find(s1);
	while (found != std::string::npos)	{
		ret += line.substr(0, found);
		ret += s2;
		line = line.substr(found + s1.length(), line.length() - found + s1.length());
		found = line.find(s2);
	}	
	return (ret + line);
}

int	main(int argc, char **argv)	{
	if (argc != 4)	{
		std::cout << "wrong argument count" << std::endl;
		std::cout << "./ex04 filename s1 s2" << std::endl;
		return (0);
	}

	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())	{
		std::cout << "unable to open " << argv[1] << std::endl;
		return (0);
	}

	std::string		line = argv[1];
	std::ofstream	ofs(line + ".replace", std::ios::out | std::ios::trunc);
	if (!ofs.is_open())	{
		ifs.close();
		std::cout << "unable to open/create output file" << std::endl;
		return (0);
	}

	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	while (std::getline(ifs, line))	{
		line = ft_replace(line, s1, s2);
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}*/
