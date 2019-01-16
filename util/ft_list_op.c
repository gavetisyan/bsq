/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:29:41 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/09 20:38:10 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*ft_create_elem(char c)
{
	t_list	*p;

	if ((p = malloc(sizeof(*p))))
	{
		p->data = c;
		p->next = NULL;
	}
	return (p);
}

int		ft_list_size(t_list *p)
{
	int	size;

	size = 0;
	while (p)
	{
		size++;
		p = p->next;
	}
	return (size);
}

void	ft_copy_list_to_arr(t_list *p, char *arr)
{
	while (p)
	{
		*arr++ = p->data;
		p = p->next;
	}
	*arr = 0;
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp_p;
	t_list	*tmp;

	tmp_p = *begin_list;
	while (tmp_p)
	{
		tmp = tmp_p->next;
		free(tmp_p);
		tmp_p = tmp;
	}
	*begin_list = NULL;
}
