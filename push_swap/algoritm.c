/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:36:52 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 14:56:34 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static int	max_digit(t_stack *stacks)
{
	int	bit_count;
	int	maxnum;

	maxnum = stacks->size_a -1;
	bit_count = 0;
	while (maxnum > 1)
	{
		bit_count ++;
		maxnum /= 2;
	}
	return (bit_count);
}

static void	radix_push_b(t_stack *stacks, int i)
{
	if (check_if_sorted(stacks) == 0)
	{
		if (((stacks->stack_a[0] >> i) & 1) == 0)
			push_to_b(stacks);
		else
			rotate_a(stacks);
	}
}

static void	radix_push_back(t_stack *stacks, int max_bits, int i)
{
	int	size;

	size = stacks->size_b;
	while (size -- && i <= max_bits)
	{
		if (((stacks->stack_b[0] >> i) & 1) == 0)
			rotate_b(stacks);
		else
			push_to_a(stacks);
	}
}

void	ft_radixsort(t_stack *stacks)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	max_bits = max_digit(stacks);
	i = 0;
	while (i <= max_bits)
	{
		size = stacks->size_a;
		j = -1;
		while (++j < size)
			radix_push_b(stacks, i);
		i ++;
		radix_push_back(stacks, max_bits, i);
	}
	while (stacks->size_b > 0)
		push_to_a(stacks);
}

void	indexing(t_stack *stacks)
{
	int	i;
	int	j;

	stacks->index = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!stacks->index)
	{
		free_stacks(stacks);
		exit (1);
	}
	i = -1;
	while (stacks->size_a > ++i)
	{
		j = 0;
		while (stacks->size_a > j)
		{
			if (stacks->stack_a[i] == stacks->sorted[j])
				stacks->index[i] = j;
			j++;
		}
	}
	i = -1;
	while (++i < stacks->size_a)
		stacks->stack_a[i] = stacks->index[i];
	free(stacks->index);
}
