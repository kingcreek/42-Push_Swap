/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:02:59 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/15 14:50:45 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				idx;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}t_stack;

void	sa(t_stack **stack);
void	push(t_stack **origin, t_stack **dest, char stackdest);
void	rotate(t_stack **stack, char option);
void	rr(t_stack **a, t_stack **b);
void	reverserot(t_stack **stack, char option);
void	rrr(t_stack **a, t_stack **b);
int		checkdup(t_stack *a);
int		checksorted(t_stack *stack_a);
t_stack	*lstlast(t_stack *lst);
t_stack	*process(int argc, char **argv, int *size);
void	freestr(char **lst);
void	add_back(t_stack **stack, t_stack *stack_new);
t_stack	*stack_new(int content);
void	print_error(void);
void	sort_stacks(t_stack **a, t_stack **b, int size);
void	freestacks(t_stack **a, t_stack **b);
void	freestack(t_stack **s);
void	sort_three_numbers(t_stack **a);
void	sort_more_than_three(t_stack **a, t_stack **b, int size);
void	assign_target_pos_lower_idx(t_stack **a, t_stack **b);
void	calculate_positions(t_stack *s);
void	assign_target_pos(t_stack **a, t_stack **b);
void	assign_costs(t_stack **b, int size_a, int size_b);
void	exec_optimal_movs(t_stack **a, t_stack **b, int *size_a, int *size_b);
void	rotate_until_sorted(t_stack **a, int size_a);
int		absv(int num);
#endif
