/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 14:32:40 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/13 17:30:25 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"bigint.hpp"

// ---------- CANONICAL FORM ---------- //

bigint::bigint()
{
	
}

bigint::bigint(unsigned int nbr) : _digits(std::to_string(nbr))
{
	
}

bigint::bigint(const bigint &cpy) : _digits(cpy._digits)
{
	
}

bigint	&bigint::operator =(const bigint &src)
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

// ---------- ADDITIONS ---------- //

bigint	&bigint::operator +=(const bigint &src)
{
	int carry = 0;
	int i = _digits.size() - 1;
	int j = src._digits.size() - 1;

	std::string	result;

	while (i >= 0 || j >= 0 || carry)
	{
		int	currentDigit = i >= 0 ? _digits[i] - '0' : 0;
		int	otherDigit = j >= 0 ? src._digits[j] - '0' : 0;
		int sum = currentDigit + otherDigit + carry;
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
		--i;
		--j;
	}
	std::reverse(result.begin(), result.end());
	_digits = result;
	return (*this);
}

bigint	bigint::operator +(const bigint &src) const
{
	bigint	res(*this);
	res += src;
	return (res);
}

// ---------- INCREMENTS ---------- //

bigint	&bigint::operator ++()
{
	bigint	dummy(1);
	*this += dummy;
	return (*this);
}

bigint	bigint::operator ++(int)
{
	bigint	cpy(*this);
	++(*this);
	return (cpy);
}

// ---------- INCREMENTS ---------- //

bigint	&bigint::operator <<=(unsigned int nbr)
{
	if (_digits != "0")
		_digits.append(nbr, '0');
	return (*this);
}

bigint	bigint::operator <<(unsigned int nbr) const
{
	bigint	cpy(*this);
	cpy <<= nbr;
	return (cpy);
}

bigint	&bigint::operator >>=(const bigint &src)
{
	int size = _digits.size();
	long amount = atol(src._digits.c_str());
	
	size >= amount ? _digits.erase(size - amount) : _digits = "0";
	return (*this);
}

// ---------- COMPARISONS ---------- //


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

// ---------- OSTREAM ---------- //

std::string	bigint::getDigits() const
{
	return (_digits);
}


std::ostream	&operator <<(std::ostream &out, const bigint &src)
{
	out << src.getDigits();
	
	return (out);
}
