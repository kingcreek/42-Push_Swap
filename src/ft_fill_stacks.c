/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:45:18 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/13 20:06:12 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * Ft_lstlast returns the last element of a linked list.
 * 
 * @param lst A pointer to the first element of a linked list.
 * 
 * @return The last element of the list.
 */
t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * It creates a new stack node
 * 
 * @param content the value of the node
 * 
 * @return A pointer to a new stack node.
 */
t_stack	*stack_new(int content)
{
	t_stack	*new;

	new = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (!new)
		print_error();
	new->value = content;
	new->next = NULL;
	return (new);
}

/**
 * It adds a new node to the end of a linked list
 * 
 * @param stack a pointer to a pointer to a t_stack.
 * @param stack_new the new node to add to the end of the list
 * 
 * @return The last element of the list.
 */
void	add_back(t_stack **lst, t_stack *new)
{
	t_stack		*tmp;

	if (!lst)
		return ;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}
