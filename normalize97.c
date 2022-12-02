/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize97.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:06:27 by suchua            #+#    #+#             */
/*   Updated: 2022/12/02 15:22:10 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_tdata(t_stack **a, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp->data != num)
	{
		if (tmp->data > num)
			tmp->t_data++;
		else
			i++;
		tmp = tmp->next;
	}
	tmp->t_data = i;
}

void	normalize97(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp)
	{
		set_tdata(a, tmp->data);
		tmp = tmp->next;
	}
}
