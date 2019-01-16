/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:08:51 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 21:16:12 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define TOTAL_SYMBOLS 3

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct			s_list
{
	char				data;
	struct s_list		*next;
}						t_list;

char					g_empty;

char					g_obstacle;

char					g_full;

int						g_width;

int						g_height;

void					ft_fputstr(int fd, char *str);

void					ft_bsq(int fd);

int						ft_atoi(char *str);

int						ft_isdigit(char c);

int						ft_isspace(char c);

int						ft_strncpy(char *dest, char **src, int n);

void					search(char **map);

void					kill_map(char **map, int i);

t_list					*ft_create_elem(char c);

int						ft_list_size(t_list *p);

void					ft_copy_list_to_arr(t_list *p, char *arr);

void					ft_list_clear(t_list **begin_list);

int						ft_check_1_line(char *buf);

int						ft_strlen(char *str);

char					**ft_check_valid_map(int fd);

#endif
