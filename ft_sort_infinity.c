/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:36 by suchua            #+#    #+#             */
/*   Updated: 2022/12/01 18:51:35 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_negative(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	size = get_stack_size(a);
	i = -1;
	while (++i < size)
	{
		if ((*a)->data < 0)
			pb(a, b);
		else
			ra(a, 0);
	}
}

void	ft_sort_infinity(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	num;

	push_negative(a, b);
	size = get_stack_size(*a);
	i = -1;
	while (!check_sort(a))
	{
		++i;
		j = -1;
		while (++j < size)
		{
			if (((*a)->data >> i) & 1)
				ra(a, PRINT);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
