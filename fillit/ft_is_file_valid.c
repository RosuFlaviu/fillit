/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_file_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:46:44 by frosu             #+#    #+#             */
/*   Updated: 2017/03/09 15:46:51 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		helping_function(char a[5][6], char *p, int ar[2])
{
	if (p[ar[2]] != '\n')
		a[ar[0]][ar[1]] = p[ar[2]];
	if (ar[1] == 4)
	{
		a[ar[0]][ar[1]] = '\0';
		ar[0]++;
		ar[1] = -1;
	}
}

void			initialize(int ar[3])
{
	ar[0] = 0;
	ar[1] = 0;
	ar[2] = 0;
}

int				check_line(char *p, t_map map_data[], int ar[], char a[5][6])
{
	if (ar[0] == 4)
	{
		ar[0] = 0;
		if (verify_matrix(a) == 0 || (p[ar[2] + 1] != '\0' &&
			(p[ar[2] + 1] == '.' || p[ar[2] + 1] == '#')))
			return (0);
		else
			copy_matrix(map_data, a);
		ar[2] = ar[2] + 1;
	}
	return (1);
}

int				read_file(int fd, t_map map_data[100])
{
	char	a[5][6];
	char	*p;
	int		ar[3];
	int		size;

	initialize(ar);
	p = (char*)malloc(sizeof(char*) * 100000);
	read(fd, p, 100000);
	size = ft_strlen(p);
	p[size] = '\0';
	if (basic_check(p) == 0)
		return (0);
	while (p[ar[2]])
	{
		helping_function(a, p, ar);
		if (check_line(p, map_data, ar, a) == 0)
			return (0);
		ar[2]++;
		ar[1]++;
	}
	if ((map_data[0].nr * 21 - 1) != size)
		return (0);
	return (1);
}

int				ft_is_file_valid(char *s, t_map map_data[100])
{
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		if (read_file(fd, map_data) == 0)
			return (0);
	}
	return (1);
}
