/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:24:58 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/21 15:35:32 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <stdlib.h>

int	check_if_sorted(t_stack *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a - 1)
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
	return (1);
}

int	arg_slayer(char *argv, t_stack *stacks)
{
	char	**args;
	int		i;
	int		ret;

	if (argv == NULL)
		return (ft_putendl_fd("Error\nMalloc error", 2), 0);
	args = ft_split(argv, ' ');
	i = 0;
	while (args[i])
		i++;
	stacks->size_a = i;
	stacks->size_b = 0;
	ret = stack_fill_slayed(i, args, stacks);
	return (ret);
}

void	indexing(t_stack *stacks)
{
	int	i;
	int	j;

	stacks->index = (int *)malloc(sizeof(int) * stacks->size_a);
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
