/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:26:17 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 21:23:12 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_bsq(int fd)
{
	char	**map;
	int		i;

	if (!(map = ft_check_valid_map(fd)))
	{
		ft_fputstr(2, "map error\n");
		return ;
	}
	search(map);
	i = 0;
	while (i < g_height)
	{
		write(1, map[i++], g_width);
		write(1, "\n", 1);
	}
	kill_map(map, g_height - 1);
}
