/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:40 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 17:01:02 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head, char move, t_stack *stack)
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
	{
		ft_printf("sa\n");
		stack->moves++;
	}
	else if (move == 'b')
	{
		ft_printf("sb\n");
		stack->moves++;
	}
	else if (move == 's')
		stack->moves++;
}

void	double_swap(t_stack *stack)
{
	swap(&stack->head_a, 's', stack);
	swap(&stack->head_b, 's', stack);
	ft_printf("ss\n");
}
