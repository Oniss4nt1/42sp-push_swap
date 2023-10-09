/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:07:31 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 14:51:35 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: reverse_rotate
 * -----------------
 * This function reverses rotate the list. It gets the last node of the list
 * and sets it as the first node. Then, it sets the penultimate node as the
 * last node. Finally, it sets the next node of the last node to the first node,
 * because of the circular list. 
 * 
 * @param: **head: pointer to the head of the list.
 * @param: move: move to be printed, if 'a' or 'b' it prints "rra" or "rrb", 
 * if 'r' it prints "rrr".
 * @var: *last: pointer to the last node of the list.
 * @var: *penultimate: pointer to the penultimate node of the list.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	reverse_rotate(t_node **head, char move)
{
	t_node	*last;
	t_node	*penultimate;

	if (!*head || !(*head)->next)
		return ;
	penultimate = NULL;
	last = *head;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = *head;
	*head = last;
	if (move == 'a')
		ft_printf("rra\n");
	else if (move == 'b')
		ft_printf("rrb\n");
	else if (move == 'r')
		ft_printf("rrr\n");
}

/**
 * Function: double_reverse_rr
 * -----------------
 * This function reverses rotate both lists. Basically, it calls the function
 * reverse_rotate twice, one for each list. Important to note that the move
 * printed is "rrr" for this function.
 * 
 * @param: *stack: pointer to the stack.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	double_reverse_rr(t_stack *stack)
{
	reverse_rotate(&stack->head_a, 'r');
	reverse_rotate(&stack->head_b, 'r');
}
