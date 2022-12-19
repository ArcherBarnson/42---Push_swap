/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:08:14 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/31 11:24:43 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			free(stacks->stack_a);
		if (stacks->stack_b)
			free(stacks->stack_b);
	}
	free(stacks);
	return ;
}

int	verify_stack(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!stacks)
		return (-1);
	while (i < stacks->len_a)
	{
		while (j < stacks->len_a)
		{
			if (stacks->stack_a[i] == stacks->stack_a[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	is_stack_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i + 1 < stacks->len_a)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

void	pick_algo(t_stacks *stacks)
{
	if (stacks->len_a < 2)
		return ;
	if (stacks->len_a == 2)
		sort_two(stacks->stack_a);
	if (stacks->len_a == 3)
		sort_three(stacks->stack_a, stacks->len_a);
	if (stacks->len_a == 4)
		sort_four(stacks);
	if (stacks->len_a == 5)
		sort_five(stacks);
	return ;
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	stacks = NULL;
	stacks = ft_parsing(av, stacks, 1);
	if (!stacks || verify_stack(stacks) == -1)
	{
		free_all(stacks);
		write(2, "Error\n", 6);
		return (-1);
	}
	if (is_stack_sorted(stacks) == 0)
	{
		free_all(stacks);
		return (0);
	}
	if (stacks->len_a < 6)
		pick_algo(stacks);
	else
		radix(stacks);
	free_all(stacks);
	return (0);
}
