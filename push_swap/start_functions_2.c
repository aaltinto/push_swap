/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:36:13 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 15:29:28 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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
