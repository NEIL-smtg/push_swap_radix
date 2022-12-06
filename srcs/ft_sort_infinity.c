/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:36 by suchua            #+#    #+#             */
/*   Updated: 2022/12/06 15:06:58 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimise_radix97(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	i;

	i = -1;
	size = get_stack_size(*b);
	while (++i < size)
	{
		if (((*b)->t_data >> bit) & 1)
			pa(a, b, PRINT);
		else
			rb(b, PRINT);
		//print_stack(*a, *b);
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	bit;
	int	j;
	int	size;

	bit = -1;
	while (!check_sort(a))
	{
		j = -1;
		++bit;
		size = get_stack_size(*a);
		while (++j < size)
		{
			if (((*a)->t_data >> bit) & 1)
				ra(a, PRINT);
			else
				pb(a, b, PRINT);
			//print_stack(*a, *b);
		}
		optimise_radix97(a, b, bit + 1);
	}
	while (*b)
		pa(a, b, PRINT);
}

void	ft_sort_infinity(t_stack **a, t_stack **b)
{
	radix_sort(a, b);
}
