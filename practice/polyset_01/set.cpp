/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:31:38 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/15 15:40:38 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "set.hpp"

set::set(searchable_bag &bag) : _bag(bag)
{
	
}

bool	set::has(int value) const
{
	return (_bag.has(value));
}

void	set::insert (int value)
{
	return (_bag.insert(value));
}

void	set::insert (int *array, int size)
{
	return (_bag.insert(array, size));
}

void	set::print() const
{
	return (_bag.print());
}

void	set::clear()
{
	return (_bag.clear());
}

const searchable_bag	&set::get_bag() const
{
	return (_bag);
}