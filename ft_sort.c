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

void	first_random_push(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
}

void	start_sorting(t_stack **a, t_stack **b)
{
	first_random_push(a, b);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	if (get_stack_size(*a) == 3)
		ft_sort3(a, TYPE_A);
	else
		start_sorting(a, b);
}
