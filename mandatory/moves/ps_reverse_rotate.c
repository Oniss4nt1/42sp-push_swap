/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:07:31 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/22 17:09:27 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node *last;
	t_node *penultimate;

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
	
}

void	double_reverse_rr(t_stack *stack)
{
	reverse_rotate(&stack->head_a);
	reverse_rotate(&stack->head_b);
}