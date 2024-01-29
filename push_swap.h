/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:25 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/13 15:55:40 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*sorted;
	int		*index;
	int		size_a;
	int		size_b;
	char	*store_int;
}		t_stack;

//start functions
int		stack_fill_slayed(int argc, char **argv, t_stack *stacks);
int		arg_slayer(char *argv, t_stack *stacks);
int		check_if_sorted(t_stack *stacks);
char	**ft_malloc_error(char **tab);

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

//algoritm functions
void	sort_three(t_stack *stacks);
void	sort_five(t_stack *stacks);
void	sort(t_stack *stacks);
void	ft_radixsort(t_stack *stacks);
void	indexing(t_stack *stacks);

//quicksort
void	quicksort(t_stack *stacks, int start, int end);

//free and exit functions
void	free_stacks(t_stack *arg);
void	double_free(char **arg);

#endif
