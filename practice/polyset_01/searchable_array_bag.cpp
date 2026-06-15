/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:17:41 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/15 14:35:31 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag()
{
	
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &cpy) : array_bag(cpy)
{
	
}

searchable_array_bag	&searchable_array_bag::operator =(const searchable_array_bag &src)
{
	if (this != &src)
		array_bag::operator=(src);
	return (*this);
}

searchable_array_bag::~searchable_array_bag()
{

}

bool searchable_array_bag::has(int value) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
			return (true);
	}
	return (false);
}
