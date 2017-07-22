/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:04:13 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 15:04:22 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verify_matrix(char a[5][6])
{
	int i;
	int j;
	int diz;
	int pc;

	j = 0;
	diz = 0;
	i = 0;
	pc = 0;
	while (i < 4)
	{
		while (a[i][j] != '\0')
		{
			if (a[i][j] == '#')
				diz++;
			if (a[i][j] == '.')
				pc++;
			j++;
		}
		j = 0;
		i++;
	}
	if (diz != 4 || pc != 12 || (checking_matrix(a) == 0))
		return (0);
	return (1);
}
