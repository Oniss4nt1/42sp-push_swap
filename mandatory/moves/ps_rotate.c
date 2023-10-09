/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:00:10 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 14:50:42 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: rotate
 * -----------------
 * This function rotates the list. It gets the first node of the list and sets
 * it as the last node. Then, it sets the second node as the first node. Finally,
 * it sets the next node of the last node to the first node, because of the
 * circular list.
 * 
 * @param: **head: pointer to the head of the list.
 * @param: move: move to be printed, if 'a' or 'b' it prints "ra" or "rb".
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	rotate(t_node **head, char move)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	if (move == 'a')
		ft_printf("ra\n");
	else if (move == 'b')
		ft_printf("rb\n");
}

/**
 * Function: double_rotate
 * -----------------
 * This function rotates the list a and the list b. Basically, it calls the
 * function rotate twice, one for each list. For parameter 'move', it passes
 * 'r' to the function rotate, so it prints "rr".
 * 
 * @param: *stack: pointer to the stack.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	double_rotate(t_stack *stack)
{
	rotate(&stack->head_a, 'r');
	rotate(&stack->head_b, 'r');
	ft_printf("rr\n");
}
