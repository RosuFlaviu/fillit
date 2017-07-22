/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:08:08 by frosu             #+#    #+#             */
/*   Updated: 2017/03/07 15:42:00 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_map
{
	char		a[5][6];
	int			nr;
}				t_map;

void			set_matrix(char **a, int len);
void			solver(char **a, int k, int len, t_map map_data[100]);
void			restrain(t_map map_data[100]);
void			copy_matrix(t_map map_data[100], char a[5][6]);
int				verify_matrix(char a[5][6]);
int				basic_check(char *p);
void			swap_rows(char a[5][6]);
void			swap_collumns(char a[5][6]);
int				ft_is_file_valid(char *s, t_map map_data[100]);
int				checking_matrix(char a[5][6]);

#endif
