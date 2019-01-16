/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:21:49 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 17:56:48 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strncpy(char *dest, char **src, int n)
{
	while (n)
	{
		if (**src != g_obstacle && **src != g_empty)
			return (0);
		*dest = **src;
		dest++;
		(*src)++;
		n--;
	}
	if (**src != '\n')
		return (0);
	(*src)++;
	return (1);
}
