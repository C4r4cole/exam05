/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:37:09 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/14 20:02:22 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

// CANONICAL FORM

vect2::vect2() : _x(0), _y(0)
{

}

vect2::vect2(const int x, const int y) : _x(x), _y(y)
{
	
}

vect2::vect2(const vect2 &cpy) : _x(cpy._x), _y(cpy._y)
{

}

vect2	&vect2::operator =(const vect2 &src)
{
	if (this != &src)
	{
		_x = src._x;
		_y = src._y;
	}	
	return (*this);
}

vect2::~vect2()
{
	
}

// INDEX ACCESS

int	&vect2::operator [](int index)
{
	if (index == 0)
		return (_x);
	else
		return (_y);
}

int	vect2::operator [](int index) const
{
	if (index == 0)
		return (_x);
	else
		return (_y);
}

// ADDITIONS

vect2	&vect2::operator +=(const vect2 &src)
{
	_x = _x + src._x;
	_y = _y + src._y;
	return (*this);
}

vect2	vect2::operator +(const vect2 &src) const
{
	vect2	res;
	res._x = _x + src._x;
	res._y = _y + src._y;
	return (res);
}

// SUBSTRACTIONS

vect2	&vect2::operator -=(const vect2 &src)
{
	_x = _x - src._x;
	_y = _y - src._y;
	return (*this);
}

vect2	vect2::operator -(const vect2 &src) const
{
	vect2	res;
	res._x = _x - src._x;
	res._y = _y - src._y;
	return (res);
}

// MULTIPLICATIONS

vect2	&vect2::operator *=(const int nbr)
{
	_x *= nbr;
	_y *= nbr;
	return (*this);
}

vect2	vect2::operator *(const int nbr) const
{
	vect2	res;
	
	res._x = _x * nbr;
	res._y = _y * nbr;
	return (res);
}

vect2	operator *(int nbr, const vect2 &src)
{
	return (src * nbr);
}

// UNARY OPERAND

vect2	vect2::operator -() const
{
	vect2	cpy(*this);
	
	cpy._x *= -1;
	cpy._y *= -1; 
	return (cpy);
}

// INCREMENTS

vect2	&vect2::operator ++()
{
	vect2	dummy(1, 1);
	*this += dummy;
	return (*this);
}

vect2	vect2::operator ++(int)
{
	vect2	cpy(*this);
	++(*this);
	return (cpy);
}

// DECREMENTS

vect2	&vect2::operator --()
{
	vect2	dummy(1, 1);
	*this -= dummy;
	return (*this);
}

vect2	vect2::operator --(int)
{
	vect2	cpy(*this);
	--(*this);
	return (cpy);
}

// COMPARISONS
bool	vect2::operator ==(const vect2 &src) const
{
	return (_x == src._x && _y == src._y);
}

bool	vect2::operator !=(const vect2 &src) const
{
	return (_x != src._x || _y != src._y);
}

// GETTERS

int	vect2::getX() const
{
	return (_x);
}

int	vect2::getY() const
{
	return (_y);
}

// IOSTREAM

std::ostream	&operator <<(std::ostream &out, const vect2 &src)
{
	out << "{" << src.getX() << ", " << src.getY() << "}";
	return (out);
}
