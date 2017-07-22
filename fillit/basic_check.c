/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:46:15 by frosu             #+#    #+#             */
/*   Updated: 2017/03/09 15:46:20 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	power_of_norminette(char *p, int *i, int *c, int *nr_new)
{
	*nr_new = *nr_new + 1;
	if (*nr_new % 4 == 0 && p[*i + 1] == '\0' && *c == 4)
	{
		p[*i + 1] = '\n';
		p[*i + 2] = '\0';
	}
	if (*nr_new % 5 == 0)
		*c = 4;
}

int		basic_check(char *p)
{
	int i;
	int c;
	int nr_new;

	nr_new = 0;
	i = 0;
	c = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '\n')
		{
			power_of_norminette(p, &i, &c, &nr_new);
			if (c != 4)
				return (0);
			c = 0;
		}
		if (p[i] != '\n')
			c++;
		i++;
	}
	if (nr_new < 4)
		return (0);
	return (1);
}
