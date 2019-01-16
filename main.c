/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:40:48 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/10 21:24:00 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc < 2)
	{
		ft_bsq(0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i++], O_RDONLY);
		if (fd == -1)
		{
			ft_fputstr(2, argv[i - 1]);
			ft_fputstr(2, ": file can't be open.\n");
		}
		else
		{
			ft_bsq(fd);
			if (close(fd) == -1)
				ft_fputstr(2, "file can't be closed\n");
		}
	}
	return (0);
}
