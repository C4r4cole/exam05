/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:22:54 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/12 18:38:56 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint()
{
	
}

bigint::bigint(unsigned int nbr) : _digits(std::to_string(nbr))
{
	
}

bigint::bigint(const bigint &cpy) : _digits(cpy._digits)
{
	
}

bigint &bigint::operator =(const bigint &src)
{
	if (this != &src)
	{
		_digits = src._digits;
	}
	return (*this);
}

bigint::~bigint()
{
	
}

// additions
bigint &bigint::operator +=(const bigint &src)
{
	int	carry = 0;
	int	i = _digits.size() - 1;
	int j = src._digits.size() - 1;
	
	std::string	result;

	while (i >= 0 || j >= 0 || carry)
	{
		int current_digit = i >= 0 ? _digits[i] - '0' : 0;
		int src_digit = j >= 0 ? src._digits[j] - '0' : 0;
		int sum = current_digit + src_digit + carry;
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
		--i;
		--j;
	}

	std::reverse(result.begin(), result.end());
	_digits = result;
	return (*this);
}

bigint bigint::operator +(const bigint &src) const
{
	bigint	cpy(*this);
	
	cpy += src;
	return (cpy);
}	

// increments
bigint &bigint::operator ++()
{
	return (*this += 1);
}

bigint bigint::operator ++(int)
{
	bigint cpy(*this);

	++(*this);
	return (cpy);
}

// shifts
bigint &bigint::operator <<=(unsigned int nbr)
{
	if (_digits != "0")
		_digits.append(nbr, '0');
	return (*this);
}

bigint bigint::operator <<(unsigned int nbr) const
{
	bigint	cpy(*this);
	
	cpy <<= nbr;
	return (cpy);
}

bigint &bigint::operator >>=(const bigint &src)
{
	unsigned int	size = _digits.size();
	unsigned long	amount = atol(src._digits.c_str());

	if (size >= amount)
		_digits.erase(size - amount);
	else
		_digits = "0";
		
	return (*this);
}

// comparisons
bool	bigint::operator <(const bigint &src) const
{
	if (_digits.size() != src._digits.size())
		return (_digits.size() < src._digits.size());
	else
		return (_digits < src._digits);
}

bool	bigint::operator >(const bigint &src) const
{
	return (src < *this);
}

bool	bigint::operator <=(const bigint &src) const
{
	return !(*this > src);
}

bool	bigint::operator >=(const bigint &src) const
{
	return !(*this < src);
}	

bool	bigint::operator ==(const bigint &src) const
{
	return (_digits == src._digits);
}

bool	bigint::operator !=(const bigint &src) const
{
	return (_digits != src._digits);
}

std::ostream	&operator <<(std::ostream &out, const bigint &src)
{
	out << src.getDigits();
	return (out);
}

std::string	bigint::getDigits() const
{
	return (this->_digits);
}

