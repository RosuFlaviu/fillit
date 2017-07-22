/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:00:39 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 15:00:40 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**alocate(int n)
{
	char	**p;
	int		i;
	int		j;

	p = (char**)malloc(sizeof(char*) * (n + 1));
	i = 0;
	while (i < n)
	{
		j = 0;
		p[i] = (char *)malloc(n + 1);
		while (j < n)
		{
			p[i][j] = '.';
			j++;
		}
		p[i][n] = '\0';
		i++;
	}
	p[n] = 0;
	return (p);
}

int		main(int argc, char **argv)
{
	char	**p;
	int		len;
	t_map	map_data[50];

	if (argc == 2)
	{
		if (ft_is_file_valid(argv[1], map_data) == 1 && map_data[0].nr <= 26)
		{
			restrain(map_data);
			len = 2;
			p = alocate(26);
			while (1)
			{
				solver(p, 0, len, map_data);
				len++;
			}
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit <input file>\n");
	return (0);
}
