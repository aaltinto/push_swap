/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:37:07 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/13 15:54:45 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	free_stacks(t_stack *arg)
{
	if (arg->stack_a != NULL)
		free(arg->stack_a);
	if (arg->stack_b != NULL)
		free(arg->stack_b);
	if (arg->sorted != NULL)
		free(arg->sorted);
}

void	double_free(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		free(arg[i]);
	free(arg);
}
