/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 14:33:10 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/13 17:06:00 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <string>
# include <algorithm>

class bigint
{
	private:
		std::string	_digits;
	public:
		bigint();
		bigint(unsigned int nbr);
		bigint(const bigint &cpy);
		bigint	&operator =(const bigint &src);
		~bigint();
	
		std::string	getDigits() const;

		// std::cout << "\n=== Additions ===================" << std::endl;
		bigint	&operator +=(const bigint &src);
		bigint	operator +(const bigint &src) const;
		
		// std::cout << "\n=== Increments ==================" << std::endl;
		bigint	&operator ++();
		bigint	operator ++(int);
		
		// std::cout << "\n=== Shifts ======================" << std::endl;
		bigint	&operator <<=(unsigned int nbr);
		bigint	operator <<(unsigned int nbr) const;
		bigint	&operator >>=(const bigint &src);
	
		// std::cout << "\n=== Comparisons =================" << std::endl;
		bool	operator <=(const bigint &src) const;
		bool	operator <(const bigint &src) const;
		bool	operator >(const bigint &src) const;
		bool	operator >=(const bigint &src) const;
		bool	operator ==(const bigint &src) const;
		bool	operator !=(const bigint &src) const;
		
};

std::ostream	&operator <<(std::ostream &out, const bigint &src);

#endif