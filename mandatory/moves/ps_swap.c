/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:40 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 14:50:09 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function: swap
 * -----------------
 * This function changes the order of the first two items in a list. It takes 
 * the second item and makes it the first, and takes the first item and makes 
 * it the second. If the 'move' parameter is 'a' or 'b', it prints "sa" 
 * or "sb" respectively.
 * 
 * @param: **head: pointer to the head of the list.
 * @param: move: move to be printed, if 'a' or 'b' it prints "sa" or "sb".
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	swap(t_node **head, char move)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (move == 'a')
		ft_printf("sa\n");
	else if (move == 'b')
		ft_printf("sb\n");
}

/**
 * Function: double_swap
 * -----------------
 * This function swaps the list a and the list b. Basically, it calls the
 * function swap twice, one for each list. For parameter 'move', it passes
 * 's' to the function swap, so it prints "ss".
 * 
 * @param: *stack: pointer to the stack.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	double_swap(t_stack *stack)
{
	swap(&stack->head_a, 's');
	swap(&stack->head_b, 's');
	ft_printf("ss\n");
}
