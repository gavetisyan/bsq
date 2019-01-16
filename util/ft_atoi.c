/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:47:56 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/09 22:39:21 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int	num;
	int	flag;

	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		flag = 1;
		str++;
	}
	else
		flag = 0;
	num = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (flag)
		num = -num;
	return (num);
}
