/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:43:03 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/15 15:42:56 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag()
{
	
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &cpy) : tree_bag(cpy)
{
	
}

searchable_tree_bag	&searchable_tree_bag::operator =(searchable_tree_bag &src)
{
	if (this != &src)
		tree_bag::operator=(src);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag()
{
	
}

bool	searchable_tree_bag::has(int value) const
{
	node	*tmp = tree;

	while (tmp)
	{
		if (value == tmp->value)
			return (true);
		else if (value < tmp->value)
			tmp = tmp->l;
		else
			tmp = tmp->r;
	}
	return (false);
}