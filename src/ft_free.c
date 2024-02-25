/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:35:44 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/25 14:29:11 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * It prints an error message and exits the program
 */
void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

/**
 * It frees the stack
 * 
 * @param s The stack to free
 */
void	freestack(t_stack **s)
{
	t_stack	*tmp;

	if (s)
	{
		while (*s)
		{
			tmp = (*s)->next;
			free(*s);
			(*s) = tmp;
		}
	}
}

/**
 * It frees the memory allocated for the stacks
 * 
 * @param a pointer to the first stack
 * @param b the stack to be sorted
 */
void	freestacks(t_stack **a, t_stack **b)
{
	freestack(a);
	freestack(b);
}

/**
 * This function frees a list of strings
 * 
 * @param lst The list to be freed.
 * 
 */
void	freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}
