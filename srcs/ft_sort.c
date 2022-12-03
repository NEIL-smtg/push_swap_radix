/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:51:25 by suchua            #+#    #+#             */
/*   Updated: 2022/11/08 23:51:25 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **s)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *s;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data > tmp2->data)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void	first_random_push(t_stack **a, t_stack **b)
{
	int	stk_size;

	stk_size = get_stack_size(*a);
	if (stk_size <= 5)
	{
		pb(a, b, PRINT);
		pb(a, b, PRINT);
		ft_sort3(a, TYPE_A);
		ft_sort5(a, b);
	}
	else
		ft_sort_infinity(a, b);
}

void	start_sorting(t_stack **a, t_stack **b)
{
	first_random_push(a, b);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	if (check_sort(a))
		return ;
	if (get_stack_size(*a) <= 3)
		ft_sort3(a, TYPE_A);
	else
		start_sorting(a, b);
}
