/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:34 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/13 15:54:58 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	r_rotate_a(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a[stacks->size_a -1];
	i = stacks->size_a -1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = tmp;
}

void	r_rotate_b(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b[stacks->size_b -1];
	i = stacks->size_b -1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = tmp;
}

void	rrr(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	tmp = stacks->stack_a[stacks->size_a -1];
	i = stacks->size_a;
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
	tmp = stacks->stack_b[stacks->size_b -1];
	i = stacks->size_b;
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
}
