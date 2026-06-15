/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:37:49 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/15 14:42:54 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &cpy);
		searchable_tree_bag	&operator =(searchable_tree_bag &src);
		~searchable_tree_bag();

		bool	has(int value) const;
};

#endif
