/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:25 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/13 15:59:12 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*sorted;
	int		*index;
	int		size_a;
	int		size_b;
	int		flag;
	char	*store_int;
}		t_stack;

//start functions
int		stack_fill_slayed(int argc, char *argv[], t_stack *stacks);
int		arg_slayer(char *argv, t_stack *stacks);
int		check_if_sorted(t_stack *stacks);

//move functions
void	swap_a(t_stack *stacks);
void	swap_b(t_stack *stacks);
void	ss(t_stack *stacks);

void	push_to_a(t_stack *stacks);
void	push_to_b(t_stack *stacks);

void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);
void	rr(t_stack *stacks);

void	r_rotate_a(t_stack *stacks);
void	r_rotate_b(t_stack *stacks);
void	rrr(t_stack *stacks);

//free and exit functions
void	free_stacks(t_stack *arg);
void	double_free(char **arg);

void	indexing(t_stack *stacks);
void	quicksort(t_stack *stacks, int start, int end);
int		check_flags(int *argc, char **argv);
void	print_screen(t_stack *stacks, int flag);
void	print_stacks(t_stack *stacks);
void	visualizer(t_stack *stacks);

#endif
