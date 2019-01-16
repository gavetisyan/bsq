/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:22:31 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 15:31:29 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		if (*str != g_empty && *str != g_obstacle)
			return (0);
		counter++;
		str++;
	}
	return (counter);
}
