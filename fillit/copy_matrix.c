/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:03:20 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 15:03:21 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	copy_matrix(t_map map_data[100], char a[5][6])
{
	static int	x;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a[i][j] == '#')
				map_data[x].a[i][j] = (char)(x + 'A');
			else
				map_data[x].a[i][j] = '.';
			j++;
		}
		i++;
	}
	map_data[0].nr = x + 1;
	x++;
}
