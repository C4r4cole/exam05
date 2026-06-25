/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:50:13 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/25 13:35:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int 	height;
	char	empty;
	char	obstacle;
	char	full;
}				t_map ;

typedef struct s_best
{
	int size;
	int	x;
	int	y;
}				t_best ;

#endif