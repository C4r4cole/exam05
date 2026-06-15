/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:00:24 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/15 15:04:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

# include "array_bag.hpp"
# include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	private:
	
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &cpy);
		searchable_array_bag	&operator =(const searchable_array_bag &src);
		~searchable_array_bag();

		bool	has(int value) const;
};

#endif
