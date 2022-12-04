/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substitutor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:45:40 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/08/06 19:11:11 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Substitutor.hpp"

Substitutor::Substitutor(std::string s1, std::string s2) : _s1(s1), _s2(s2)	{
	_l1 = _s1.length();
	_l2 = _s2.length();
	std::cout << "SUBSTITUTOR INITIALIZED" << std::endl;
}

Substitutor::~Substitutor(void)	{
	std::cout << "SUBSTITUTOR IS NO MORE" << std::endl;
}

std::string	Substitutor::substitute(std::string line)	{
	std::size_t	found;
	
	if (_l1)	{
		found = line.find(_s1);
		while (found != std::string::npos)	{
			line.erase(found, _l1);
			line.insert(found, _s2);
			found = line.find(_s1, found + _l2);
		}	
	}
	return (line);
}
