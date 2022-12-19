/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:41:36 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/30 16:15:51 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cpy_tab(int *tab, int tab_size)
{
	int	i;
	int	*dest;

	i = -1;
	dest = malloc(sizeof(int) * tab_size);
	if (!dest)
		return (0);
	while (++i < tab_size)
		dest[i] = tab[i];
	return (dest);
}

int	*bubble_sort(int *tab, int tab_size)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted_tab;

	i = -1;
	j = 0;
	tmp = 0;
	sorted_tab = cpy_tab(tab, tab_size);
	i = -1;
	while (++i < tab_size)
	{
		j = i;
		while (++j < tab_size)
		{
			if (sorted_tab[i] > sorted_tab[j])
			{
				tmp = sorted_tab[j];
				sorted_tab[j] = sorted_tab[i];
				sorted_tab[i] = tmp;
			}
		}
	}
	return (sorted_tab);
}

int	*n_to_index(int *tab, int tab_size)
{
	int	*sorted_tab;
	int	i;
	int	j;

	i = 0;
	sorted_tab = bubble_sort(tab, tab_size);
	while (i < tab_size)
	{
		j = 0;
		while (j < tab_size && i < tab_size)
		{
			if (tab[i] == sorted_tab[j])
			{
				tab[i] = j;
				i++;
			}
			j++;
		}
	}
	free(sorted_tab);
	return (tab);
}

int	get_max_binary(int *tab, int tab_len)
{
	int	max;
	int	*sorted;

	max = 1;
	sorted = bubble_sort(tab, tab_len);
	while (sorted[tab_len - 1] >= 2)
	{
		sorted[tab_len - 1] /= 2;
		max++;
	}
	free(sorted);
	return (max);
}

void	radix(t_stacks *stacks)
{
	int	i;
	int	j;
	int	len;
	int	max;

	j = 0;
	len = stacks->len_a;
	stacks->stack_a = n_to_index(stacks->stack_a, stacks->len_a);
	max = get_max_binary(stacks->stack_a, stacks->len_a);
	while (j < max)
	{
		i = 0;
		while (i < len)
		{
			if ((stacks->stack_a[0] >> j) % 2 == 0)
				pb(stacks);
			else
				r(stacks->stack_a, stacks->len_a, 'a');
			i++;
		}
		while (stacks->len_b != 0)
			pa(stacks);
		j++;
	}
}
