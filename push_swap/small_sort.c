/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:34 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/26 11:11:44 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	partition(t_stack *stacks, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = stacks->sorted[end];
	i = start -1;
	j = start;
	while (j <= end -1)
	{
		if (stacks->sorted[j] < pivot)
		{
			i++;
			tmp = stacks->sorted[i];
			stacks->sorted[i] = stacks->sorted[j];
			stacks->sorted[j] = tmp;
		}
		j++;
	}
	i++;
	tmp = stacks->sorted[i];
	stacks->sorted[i] = stacks->sorted[end];
	stacks->sorted[end] = tmp;
	return (i);
}

void	quicksort(t_stack *stacks, int start, int end)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = partition(stacks, start, end);
	quicksort(stacks, start, pivot -1);
	quicksort(stacks, pivot +1, end);
}

void	sort_three(t_stack *stacks)
{
	if (check_if_sorted(stacks) == 1)
		return ;
	if (stacks->stack_a[0] > stacks->stack_a[1])
	{
		if (stacks->stack_a[0] > stacks->stack_a[2])
			rotate_a(stacks);
		else
			swap_a(stacks);
	}
	else if (stacks->stack_a[0] < stacks->stack_a[1])
		r_rotate_a(stacks);
	if (check_if_sorted(stacks) == 0)
		sort_three(stacks);
}

void	sort_five_2(t_stack *stacks, int i, int j)
{
	if (i <= 2)
	{
		while (stacks->stack_a[0] != j)
			rotate_a(stacks);
	}
	else
	{
		while (stacks->stack_a[0] != j)
			r_rotate_a(stacks);
	}
	push_to_b(stacks);
}

void	sort_five(t_stack *stacks)
{
	int	i;
	int	j;

	j = 0;
	while (stacks->size_a != 3)
	{
		i = 0;
		while (stacks->stack_a[i] != j)
			i++;
		sort_five_2(stacks, i, j);
		j ++;
	}
	if (!check_if_sorted(stacks))
		sort_three(stacks);
	while (stacks->size_b > 0)
		push_to_a(stacks);
}
