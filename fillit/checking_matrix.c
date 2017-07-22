/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:59:33 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 14:59:34 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		poower(char a[5][6], int i, int j)
{
	int contor;

	contor = 0;
	while (a[i][j] != '\0' && j < 4)
	{
		if (a[i][j] == '#')
		{
			if (i > 0 && a[i - 1][j] == '#')
				contor++;
			if (j > 0 && a[i][j - 1] == '#')
				contor++;
			if (i < 4 && a[i + 1][j] == '#')
				contor++;
			if (j < 4 && a[i][j + 1] == '#')
				contor++;
		}
		j++;
	}
	return (contor);
}

int		checking_matrix(char a[5][6])
{
	int i;
	int j;
	int contor;

	swap_collumns(a);
	swap_rows(a);
	i = 0;
	contor = 0;
	while (i < 4 && a[i] != '\0')
	{
		j = 0;
		contor += poower(a, i, j);
		i++;
	}
	if (contor == 0 || (contor != 6 && contor != 8))
		return (0);
	return (1);
}
