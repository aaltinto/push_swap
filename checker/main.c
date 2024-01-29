/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:36:08 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/21 15:48:32 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>

void	exec2(char *line, t_stack *stacks)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		r_rotate_a(stacks);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		r_rotate_b(stacks);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stacks);
}

char	*exec(char *line, int *check, t_stack *stacks)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a(stacks);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_b(stacks);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_to_a(stacks);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_to_b(stacks);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a(stacks);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b(stacks);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stacks);
	else if (ft_strncmp(line, "rra\n", 4) == 0
		|| ft_strncmp(line, "rrb\n", 4) == 0
		|| ft_strncmp(line, "rr\n", 3) == 0)
		exec2(line, stacks);
	else
		return (*check = 0, free(line),
			ft_putendl_fd("Error\nUndefined move", 2), NULL);
	free(line);
	return (get_next_line(0));
}

int	seek_n_exec(t_stack *stacks, int flag)
{
	char	*line;
	int		check;

	check = 1;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (flag == 2)
			print_stacks(stacks);
		if (flag == 3)
			visualizer(stacks);
		line = exec(line, &check, stacks);
	}
	free(line);
	if (flag == 2)
		print_stacks(stacks);
	if (flag == 3)
		visualizer(stacks);
	if (check == 0)
		return (0);
	else
		return (1);
}

void	ints_assemble(t_stack *stacks, char **argv, int argc)
{
	int		i;
	char	*tmp;

	stacks->store_int = NULL;
	i = 1;
	while (argv[i] && i < argc)
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
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	stacks.flag = check_flags(&argc, argv);
	if (argc < 2)
		exit(EXIT_FAILURE);
	else
		ints_assemble(&stacks, argv, argc);
	if (!arg_slayer(stacks.store_int, &stacks))
		return (free(stacks.store_int), 1);
	free(stacks.store_int);
	if (stacks.flag == -1)
		return (1);
	if (stacks.flag == 3)
	{
		quicksort(&stacks, 0, stacks.size_a -1);
		indexing(&stacks);
	}
	if (!seek_n_exec(&stacks, stacks.flag))
		return (free_stacks(&stacks), 1);
	print_screen(&stacks, stacks.flag);
	free_stacks(&stacks);
	return (EXIT_SUCCESS);
}
