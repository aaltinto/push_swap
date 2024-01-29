/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:24:46 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/13 15:54:56 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rotate_a(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a -1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a -1] = tmp;
}

void	rotate_b(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_b[0];
	i = 0;
	while (++i < stacks->size_b)
		stacks->stack_b[i - 1] = stacks->stack_b[i];
	stacks->stack_b[i - 1] = tmp;
}

void	rr(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	tmp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a -1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a -1] = tmp;
	tmp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b -1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b -1] = tmp;
}
