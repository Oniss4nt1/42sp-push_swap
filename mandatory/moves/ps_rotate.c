/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:00:10 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/25 17:35:15 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **head, char move, t_stack *stack)
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
	
	if (move == 'a')
		ft_printf("ra\n");
	else if (move == 'b')
		ft_printf("rb\n");
	else if (move == 'r')
		ft_printf("rr\n");
	print_stacks(stack);
}

void	double_rotate(t_stack *stack)
{
	rotate(&stack->head_a, 'r', stack);
	rotate(&stack->head_b, 'r', stack);
}