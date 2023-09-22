/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:00:10 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/22 17:09:34 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **head)
{
	t_node *first;
	t_node *last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

void	double_rotate(t_stack *stack)
{
	rotate(&stack->head_a);
	rotate(&stack->head_b);
}