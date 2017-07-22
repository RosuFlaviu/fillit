/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:04:53 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 15:04:54 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_rows(char a[5][6])
{
	int k;

	k = 3;
	while (a[0][k] == '.' && a[1][k] == '.' && a[2][k] == '.' && a[3][k] == '.')
	{
		a[0][k] = '\0';
		a[1][k] = '\0';
		a[2][k] = '\0';
		a[3][k] = '\0';
		k--;
	}
}

void	delete_cols(char a[5][6])
{
	int k;
	int len;
	int i;

	k = 3;
	len = ft_strlen(a[0]);
	i = len;
	while (i == len)
	{
		i = 0;
		while (a[k][i] != '\0' && a[k][i] == '.')
			i++;
		if (i == len)
		{
			a[k][0] = '\0';
			a[k][1] = '\0';
			a[k][2] = '\0';
			a[k][3] = '\0';
			len = ft_strlen(a[0]);
			i = len;
		}
		k--;
	}
}

void	restrain(t_map map_data[100])
{
	int i;

	i = 0;
	while (i < map_data[0].nr)
	{
		delete_rows(map_data[i].a);
		delete_cols(map_data[i].a);
		i++;
	}
}
