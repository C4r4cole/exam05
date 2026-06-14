/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:42:19 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/14 19:54:17 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>
# include <string>
# include <algorithm>

class vect2
{
	private:
		int _x;
		int	_y;
	
	public:
	// CANONICAL FORM
		vect2();
		vect2(const int x, const int y);
		vect2(const vect2 &cpy);
		vect2	&operator =(const vect2 &src);
		~vect2();
	
	// INDEX ACCESS
		int	&operator [](int index);
		int	operator [](int index) const;

	// ADDITIONS
		vect2	&operator +=(const vect2 &src);
		vect2	operator +(const vect2 &src) const;

	// SUBSTRACTIONS
		vect2	&operator -=(const vect2 &src);
		vect2	operator -(const vect2 &src) const;

	// MULTIPLICATIONS
		vect2	&operator *=(const int nbr);
		vect2	operator *(const int nbr) const;

	// UNARY OPERAND
		vect2	operator -() const;

	// INCREMENTS
		vect2	&operator ++();
		vect2	operator ++(int);
		
	// DECREMENTS
		vect2	&operator --();
		vect2	operator --(int);

	// COMPARISONS
		bool	operator ==(const vect2 &src) const;
		bool	operator !=(const vect2 &src) const;
		
	// GETTERS
		int	getX() const;
		int	getY() const;

};

// IOSTREAM
std::ostream	&operator <<(std::ostream &out, const vect2 &src);

// MULTIPLICATIONS
vect2			operator *(int nbr, const vect2 &src);

#endif