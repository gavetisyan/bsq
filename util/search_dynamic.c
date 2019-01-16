/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dynamic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:46:48 by bgilwood          #+#    #+#             */
/*   Updated: 2018/10/10 20:13:40 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		find_min(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	delete_array(int **array)
{
	int i;

	i = 0;
	while (i < g_height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	update_map(char **map, int **num_array, int size)
{
	int i;
	int j;
	int x;
	int y;

	y = -1;
	while (++y < g_height)
	{
		x = -1;
		while (++x < g_width)
		{
			if (num_array[y][x] == size)
			{
				delete_array(num_array);
				i = -1;
				while (++i < size)
				{
					j = -1;
					while (++j < size)
						map[y + i][x + j] = g_full;
				}
				return ;
			}
		}
	}
}

int		dynam_search(char **map, int **num_array, int max)
{
	int i;
	int j;

	i = g_height - 1;
	while (--i > -1)
	{
		j = g_width - 1;
		while (--j > -1)
		{
			if (map[i][j] == g_obstacle)
				num_array[i][j] = 0;
			else
				num_array[i][j] = 1 +
					find_min(num_array[i + 1][j], num_array[i][j + 1],
							num_array[i + 1][j + 1]);
			if (num_array[i][j] > max)
				max = num_array[i][j];
		}
	}
	return (max);
}

void	search(char **map)
{
	int	i;
	int	**num_array;
	int max;

	max = 0;
	num_array = (int**)malloc(sizeof(int*) * g_height);
	i = -1;
	while (++i < g_height)
	{
		num_array[i] = (int*)malloc(sizeof(int) * g_width);
		num_array[i][g_width - 1] = map[i][g_width - 1] == g_empty ? 1 : 0;
		if (num_array[i][g_width - 1] == 1)
			max = 1;
	}
	i = g_width;
	while (--i > -1)
	{
		num_array[g_height - 1][i] = map[g_height - 1][i] == g_empty ? 1 : 0;
		if (num_array[g_height - 1][i] == 1)
			max = 1;
	}
	max = dynam_search(map, num_array, max);
	update_map(map, num_array, max);
}
