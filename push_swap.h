/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:04:13 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/31 12:13:26 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
}	t_stacks;

t_stacks	*fill_stack(char **av, t_stacks *stacks);
t_stacks	*ft_parsing(char **av, t_stacks *stack, int i);
long long	ft_atoll(const char *str);
int			ft_atoi(const char *str);
int			verify_str(char *str);
int			get_ints(char *str, int *stack, int stack_pos);
int			*cpy_tab(int *tab, int tab_size);
int			*bubble_sort(int *tab, int tab_size);
int			*n_to_index(int *tab, int tab_size);
int			get_last_bit(int n);
int			verify_stack(t_stacks *stacks);
int			ft_strlen(char *str);
void		free_all(t_stacks *stacks);
void		ft_bzero(char *str);
void		byteshift_tab(int *tab, int tab_size);
void		radix(t_stacks *stacks);
void		offset_stack_down(int *tab, int tab_len);
void		offset_stack_up(int *tab, int tab_len);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		s(int *stack, char name);
void		ss(t_stacks *stacks);
void		r(int *stack, int stack_len, char name);
void		rr(t_stacks *stacks);
void		rrx(int *stack, int stack_len, char x);
void		rrr(t_stacks *stacks);
void		push_nmin(t_stacks *stacks);
void		sort_two(int *stack);
void		sort_three(int *stack, int stack_len);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);

#endif
