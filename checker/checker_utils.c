/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:20:42 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 15:01:45 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	print_screen(t_stack *stacks, int flag)
{
	int	result;

	result = 1;
	if (!check_if_sorted(stacks) || stacks->size_b != 0)
		result = 0;
	if (flag != 0)
	{
		if (result == 0)
			ft_putstr_fd("\033[0;31m", 1);
		else
			ft_putstr_fd("\033[0;32m", 1);
	}
	if (result == 0)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
}

void	print_stacks(t_stack *stacks)
{
	int		i;
	int		j;
	char	*num;

	i = -1;
	j = -1;
	while (++i < stacks->size_a)
	{
		num = ft_itoa(stacks->stack_a[i]);
		ft_putstr_fd(num, 1);
		free(num);
		if (++j < stacks->size_b)
		{
			ft_putstr_fd("           ", 1);
			num = ft_itoa(stacks->stack_b[i]);
			ft_putstr_fd(num, 1);
			free(num);
		}
		ft_putendl_fd(" ", 1);
	}
	ft_putstr_fd("---         ---\n a           b\n\n", 1);
}

void	print_a(t_stack *stacks, int i, int j)
{
	int	space;
	int	k;

	if (i < stacks->size_a)
	{
		j = stacks->stack_a[i] + 1;
		space = 20 - j;
		while (j-- > 0)
			ft_putchar_fd('.', 1);
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		k = 0;
		while (k++ < 20)
			ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd("          ", 1);
}

void	visualizer(t_stack *stacks)
{
	int	i;
	int	j;

	ft_putendl_fd("stack a:    		      stacks b:", 1);
	i = 0;
	while (i < stacks->size_a || i < stacks->size_b)
	{
		print_a(stacks, i, j);
		if (i < stacks->size_b)
		{
			j = stacks->stack_b[i] + 1;
			while (j-- > 0)
				ft_putchar_fd('.', 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putendl_fd("\n", 1);
	usleep(200000);
}

int	check_flags(int *argc, char **argv)
{
	if (!ft_strncmp(argv[*argc -1], "-c", 2))
		return (*argc = *argc -1, 1);
	else if (!ft_strncmp(argv[*argc -1], "-s", 2))
		return (*argc = *argc -1, 2);
	else if (!ft_strncmp(argv[*argc -1], "-v", 2))
		return (*argc = *argc -1, 3);
	else
		return (0);
}
