/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:30:16 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/25 14:35:22 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	
	int		height;
	int		width;
	
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