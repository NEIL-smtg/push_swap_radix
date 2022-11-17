/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:45:02 by suchua            #+#    #+#             */
/*   Updated: 2022/11/09 23:45:02 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->cost = 0;
}

void	stack_add_front(t_stack **s, t_stack *add)
{
	if (!s || !*s)
		*s = add;
	else
	{
		add->next = *s;
		*s = add;
	}
}

void	stack_add_back(t_stack **s, t_stack *new)
{
	t_stack	*last;

	new->next = NULL;
	if (!s || !*s)
		*s = new;
	else
	{
		last = get_last_elem(*s);
		last->next = new;
	}
}
