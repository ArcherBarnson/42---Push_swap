/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_algos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:54:44 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/31 16:52:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nmin(t_stacks *stacks)
{
	int	i;
	int	n;
	int	index;

	i = -1;
	n = 0;
	index = 0;
	while (++i < stacks->len_a)
	{
		if (i == 0 || stacks->stack_a[i] < n)
		{
			n = stacks->stack_a[i];
			index = i;
		}
	}
	while (stacks->stack_a[0] != n)
	{
		if (index <= stacks->len_a / 2)
			r(stacks->stack_a, stacks->len_a, 'a');
		else
			rrx(stacks->stack_a, stacks->len_a, 'a');
	}
	pb(stacks);
	return ;
}

void	sort_two(int *stack)
{
	if (stack[0] > stack[1])
		s(stack, 'a');
	return ;
}

void	sort_three(int *stack, int stack_len)
{
	while (1)
	{
		if (stack[0] < stack[1] && stack[1] < stack[2])
			break ;
		if (stack[0] > stack[1] && stack[1] > stack[2])
			rrx(stack, stack_len, 'a');
		if (stack[0] < stack[1] && stack[1] > stack[2])
			s(stack, 'a');
		if (stack[0] > stack[1] && stack[1] < stack[2])
			r(stack, stack_len, 'a');
	}
	return ;
}

void	sort_four(t_stacks *stacks)
{
	push_nmin(stacks);
	sort_three(stacks->stack_a, stacks->len_a);
	pa(stacks);
	return ;
}

void	sort_five(t_stacks *stacks)
{
	push_nmin(stacks);
	sort_four(stacks);
	pa(stacks);
	return ;
}
