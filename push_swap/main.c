/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:37:23 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 15:29:04 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	sort(t_stack *stacks)
{
	quicksort(stacks, 0, stacks->size_a -1);
	indexing(stacks);
	if (stacks->size_a == 2)
		swap_a(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a <= 5)
		sort_five(stacks);
	else
		ft_radixsort(stacks);
}

void	ints_assemble(t_stack *stacks, char **argv)
{
	int		i;
	char	*tmp;

	stacks->store_int = NULL;
	i = 0;
	while (argv[++i])
	{
		if (!stacks->store_int)
			stacks->store_int = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(stacks->store_int, " ");
			free(stacks->store_int);
			stacks->store_int = ft_strjoin(tmp, argv[i]);
			free(tmp);
			if (stacks->store_int == NULL)
				return ;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	if (argc < 2)
		return (ft_putendl_fd("Error", 2), 1);
	else
		ints_assemble(&stacks, argv);
	if (!arg_slayer(stacks.store_int, &stacks))
		return (free_stacks(&stacks), free(stacks.store_int), 1);
	free(stacks.store_int);
	if (check_if_sorted(&stacks) == 0)
		sort(&stacks);
	free_stacks(&stacks);
}
