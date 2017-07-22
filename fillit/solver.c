/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:06:41 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 15:06:42 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	afisare(char **a, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			ft_putchar(a[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		can_put_in_matrix(char **a, int ar[2], char to_put[5][6], int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (to_put[i][0] != '\0')
	{
		while (to_put[i][j] != '\0')
		{
			if ((to_put[i][j] != '.' && a[ar[0] + i][ar[1] + j] != '.')
					|| (ar[0] + i >= len || ar[1] + j >= len))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	put_in_matrix(char **a, int ar[2], char to_put[5][6], int len)
{
	int	i;
	int	j;

	i = 0;
	while (to_put[i][0] != '\0' && i < len)
	{
		j = 0;
		while (to_put[i][j] != '\0' && j < len)
		{
			if (to_put[i][j] != '.')
				a[ar[0] + i][ar[1] + j] = to_put[i][j];
			j++;
		}
		i++;
	}
}

void	clear_piece(char ***a, int k, int len)
{
	int		i;
	int		j;
	char	**c;

	c = *a;
	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (c[i][j] == 'A' + k)
				c[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	*a = c;
}

void	solver(char **a, int k, int len, t_map map_data[100])
{
	int ar[2];

	ar[0] = 0;
	ar[1] = 0;
	while (ar[0] < len && k <= map_data[0].nr)
	{
		while (ar[1] < len && k <= map_data[0].nr)
		{
			clear_piece(&a, k, len);
			if (can_put_in_matrix(a, ar, map_data[k].a, len) == 1)
			{
				put_in_matrix(a, ar, map_data[k].a, len);
				if (k == map_data[0].nr)
				{
					afisare(a, len);
					exit(0);
				}
				solver(a, k + 1, len, map_data);
			}
			ar[1]++;
		}
		ar[0]++;
		ar[1] = 0;
	}
}
