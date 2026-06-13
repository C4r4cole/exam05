/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:22:59 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/12 18:31:44 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BIGINT_HPP
#define BIGINT_HPP

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
		bigint &operator =(const bigint &src);
		~bigint();

		// additions
		bigint operator +(const bigint &src) const;
		bigint &operator +=(const bigint &src);

		// increments
		bigint &operator ++();
		bigint operator++(int);

		// shifts
		bigint operator <<(unsigned int nbr) const;
		bigint &operator <<=(unsigned int nbr);
		bigint &operator >>=(const bigint &src);

		// comparisons
		bool	operator >(const bigint &src) const;
		bool	operator <(const bigint &src) const;
		bool	operator >=(const bigint &src) const;
		bool	operator <=(const bigint &src) const;
		bool	operator ==(const bigint &src) const;
		bool	operator !=(const bigint &src) const;

		std::string	getDigits() const;
};

// ostream
std::ostream	&operator <<(std::ostream &out, const bigint &src);
	
#endif