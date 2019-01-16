/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_1_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:45:43 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 18:32:29 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_check_1_line(char *buf)
{
	int		total_lines;
	int		num_char;
	char	arr[3];

	total_lines = ft_atoi(buf);
	while (ft_isspace(*buf))
		buf++;
	while (ft_isdigit(*buf))
		buf++;
	num_char = 0;
	while (num_char < TOTAL_SYMBOLS)
	{
		if (!(*buf))
			return (0);
		arr[num_char++] = *buf++;
	}
	if (*buf != 0 || total_lines < 1)
		return (0);
	g_empty = arr[0];
	g_obstacle = arr[1];
	g_full = arr[2];
	if (g_empty == g_obstacle || g_empty == g_full || g_obstacle == g_full)
		return (0);
	return (total_lines);
}
