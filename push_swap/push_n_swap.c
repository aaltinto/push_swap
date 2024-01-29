/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:37:45 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 15:28:59 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	swap_a(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a[1];
	stacks->stack_a[1] = stacks->stack_a[0];
	stacks->stack_a[0] = tmp;
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b[1];
	stacks->stack_b[1] = stacks->stack_b[0];
	stacks->stack_b[0] = tmp;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	tmp = stacks->stack_a[1];
	stacks->stack_a[1] = stacks->stack_a[0];
	stacks->stack_a[0] = tmp;
	tmp = stacks->stack_b[1];
	stacks->stack_b[1] = stacks->stack_b[0];
	stacks->stack_b[0] = tmp;
	ft_putendl_fd("ss", 1);
}

void	push_to_a(t_stack *stacks)
{
	int	i;

	if (stacks->size_b)
	{
		stacks->size_a++;
		i = stacks->size_a;
		while (--i > 0)
			stacks->stack_a[i] = stacks->stack_a[i - 1];
		stacks->stack_a[0] = stacks->stack_b[0];
		stacks->size_b--;
		i = -1;
		while (++i < stacks->size_b)
			stacks->stack_b[i] = stacks->stack_b[i + 1];
		ft_putendl_fd("pa", 1);
	}
}

void	push_to_b(t_stack *stacks)
{
	int	i;

	if (stacks->size_a)
	{
		stacks->size_b++;
		i = stacks->size_b;
		while (--i > 0)
			stacks->stack_b[i] = stacks->stack_b[i - 1];
		stacks->stack_b[0] = stacks->stack_a[0];
		stacks->size_a--;
		i = -1;
		while (++i < stacks->size_a)
			stacks->stack_a[i] = stacks->stack_a[i + 1];
		ft_putendl_fd("pb", 1);
	}
}
