/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:02:44 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/15 14:11:32 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * It returns the index of the biggest number in the stack
 * 
 * @param a pointer to the stack a
 * 
 * @return The biggest index of the stack.
 */
static	int	biggest_index(t_stack **a)
{
	t_stack	*aux_a;
	int		biggest;

	aux_a = *a;
	biggest = aux_a->idx;
	while (aux_a)
	{
		if (aux_a->idx > biggest)
			biggest = aux_a->idx;
		aux_a = aux_a->next;
	}
	return (biggest);
}

/**
 * It assigns the target position of the element 
 * at the top of stack b, by finding the closest element
 * to the top of stack b in stack a
 * 
 * @param a pointer to the head of the stack a
 * @param b the stack that we want to move
 */
void	assign_target_pos_lower_idx(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	int		closer_idx;
	int		target_pos;

	aux_a = *a;
	closer_idx = biggest_index(&aux_a);
	while (aux_a)
	{
		if ((*b)->idx < aux_a->idx && closer_idx > aux_a->idx)
		{
			closer_idx = aux_a->idx;
			target_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	(*b)->target_pos = target_pos;
}
