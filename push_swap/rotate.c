/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:01 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 15:28:52 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b -1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b -1] = tmp;
	ft_putendl_fd("rb", 1);
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
	ft_putendl_fd("rr", 1);
}
