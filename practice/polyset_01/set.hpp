/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:02:14 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/15 15:38:06 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag	&_bag;
	public:
		set(searchable_bag &bag);
		
		bool	has(int value) const;
		
		void	insert (int value);
		void	insert (int *array, int size);
		void	print() const;
		void	clear();
		
		const searchable_bag	&get_bag() const;
};

#endif