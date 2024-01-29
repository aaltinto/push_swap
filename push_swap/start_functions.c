/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:42 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/24 15:29:32 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

static long	ft_strtol(char *str)
{
	long	i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		res = (str[i++] - 48) + (res * 10);
	return (res * s);
}

static int	check_doubles(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = i;
		while (args[++j])
		{
			if (!ft_strncmp(args[i], args[j], 11))
			{
				ft_putendl_fd("Error\nIdentical values", 2);
				double_free(args);
				return (0);
			}
		}
	}
	return (1);
}

static int	checker(char **argv, int i)
{
	int	j;
	int	check;

	while (argv[++i])
	{
		j = -1;
		check = 0;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& argv[i][j + 1] == '\0')
				return (double_free(argv),
					ft_putendl_fd("Error\nInvalid character", 2), 0);
			if (!ft_isdigit(argv[i][j]))
				if ((argv[i][j] != '-' && argv[i][j] != '+') || ++check != 1)
					return (ft_putendl_fd("Error\nInvalid character", 2),
						double_free(argv), 0);
		}
	}
	return (1);
}

int	stack_fill_slayed(int argc, char *argv[], t_stack *stacks)
{
	int		i;
	long	val;

	stacks->stack_a = (int *)malloc(sizeof(int) * (argc));
	stacks->stack_b = (int *)malloc(sizeof(int) * (argc));
	stacks->sorted = (int *)malloc(sizeof(int) * (argc));
	if (!checker(argv, -1) || !check_doubles(argv))
		return (0);
	if (stacks->stack_a == NULL || stacks->sorted == NULL
		|| stacks->stack_b == NULL)
		return (ft_putendl_fd("Error\nMalloc error", 2),
			double_free(argv), 0);
	i = -1;
	while (++i < argc)
	{
		val = ft_strtol(argv[i]);
		if (val < -2147483648 || val > 2147483647)
			return (ft_putendl_fd("Error\nInput out of range", 2),
				double_free(argv), 0);
		stacks->stack_a[i] = (int)val;
	}
	ft_memcpy(stacks->sorted, stacks->stack_a, stacks->size_a);
	return (double_free(argv), 1);
}
