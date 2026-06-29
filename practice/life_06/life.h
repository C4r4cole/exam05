/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:44:40 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/29 14:57:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		iteration;
}				t_game ;

#endif