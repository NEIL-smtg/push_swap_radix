/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:18:30 by suchua            #+#    #+#             */
/*   Updated: 2022/12/02 14:56:22 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("%6c\t%14c\n", 'a', 'b');
	while (a)
	{
		if (b)
			ft_printf("|%11d  |\t|%11d  |\n", a->data, b->data);
		else
			ft_printf("|%11d  |\t|%11c  |\n", a->data, 'n');
		a = a->next;
		if (b)
			b = b->next;
	}
}

void	do_ops(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "pa", 3))
		pa(a, b);
	else if (ft_strncmp(op, "pb", 3))
		pb(a, b);
	else
	{
		free(op);
		ft_clear_stack(a);
		ft_clear_stack(b);
		exit_now();
	}
}

void	clean(char *ops)
{
	int	i;

	i = -1;
	while (++i < 3)
		ops[i] = 0;
}

void	get_the_line(t_stack **a, t_stack **b)
{
	char	*ops;

	ops = malloc(sizeof(char) * 3);
	while (1)
	{
		clean(ops);
		ops = get_next_line(STDIN);
		do_ops(ops, a, b);
	}
	free(ops);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 2)
	{
		stack_a = ft_check_valid(ac, av);
		print_stack(stack_a, stack_b);
		// get_the_line(&stack_a, &stack_b);
		ft_clear_stack(&stack_a);
		ft_clear_stack(&stack_b);
	}
	return (0);
}
