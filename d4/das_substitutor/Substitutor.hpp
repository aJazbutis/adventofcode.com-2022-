/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substitutor.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:44:46 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/08/05 19:04:00 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSTITUTOR_HPP
#define SUBSTITUTOR_HPP

# include <iostream>
# include <fstream>

class	Substitutor	{
	private:
		std::string	_s1;
		std::string	_s2;
		std::size_t	_l1;
		std::size_t	_l2;
	public:
		Substitutor(std::string	s1, std::string	s2);
		~Substitutor(void);
		std::string substitute(std::string line);
};

#endif
