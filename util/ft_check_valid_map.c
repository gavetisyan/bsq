/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:51:00 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 21:29:29 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char		*remember_line(t_list **begin)
{
	char	*str;

	if (begin == NULL)
		return (0);
	if (!(str = malloc(sizeof(*str) * (ft_list_size(*begin) + 1))))
	{
		ft_list_clear(begin);
		return (0);
	}
	ft_copy_list_to_arr(*begin, str);
	ft_list_clear(begin);
	return (str);
}

char		*pop_line(int fd)
{
	int		ret;
	t_list	*tmp;
	t_list	*begin;
	char	buf[1];

	begin = NULL;
	while (1)
	{
		if (!(ret = read(fd, buf, 1)))
			return (0);
		if (buf[0] == '\n')
			break ;
		if (begin == NULL)
		{
			tmp = ft_create_elem(buf[0]);
			begin = tmp;
		}
		else
		{
			tmp->next = ft_create_elem(buf[0]);
			tmp = tmp->next;
		}
	}
	return (remember_line(&begin));
}

void		kill_map(char **map, int i)
{
	while (i >= 0)
	{
		if (map[i])
			free(map[i]);
		i--;
	}
	free(map);
}

int			pop_rest(char **map, int fd)
{
	int		volume;
	int		ret;
	int		i;
	char	*buf;
	char	*start;

	volume = (g_height - 1) * (g_width + 1);
	buf = malloc(sizeof(*buf) * (volume + 1));
	start = buf;
	ret = 0;
	while ((i = read(fd, buf + ret, (volume + 1))))
		ret += i;
	if (ret != volume)
		return (0);
	i = 1;
	while (i < g_height)
	{
		*++map = malloc(sizeof(*buf) * g_width);
		if (!(ft_strncpy(*map, &buf, g_width)))
			return (0);
		i++;
	}
	free(start);
	return (1);
}

char		**ft_check_valid_map(int fd)
{
	char	**map;
	char	*buf;
	int		i;

	if (!(buf = pop_line(fd)))
		return (0);
	if (!(g_height = ft_check_1_line(buf)))
		return (0);
	map = malloc(sizeof(*map) * (g_height));
	i = -1;
	while (++i < g_height)
		map[i] = NULL;
	if (!(*map = pop_line(fd)))
		return (0);
	if (!(g_width = ft_strlen(*map)))
	{
		kill_map(map, 1);
		return (0);
	}
	if (!(pop_rest(map, fd)))
	{
		kill_map(map, g_height - 1);
		return (0);
	}
	return (map);
}
