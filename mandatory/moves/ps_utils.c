/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:12:44 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/26 14:52:11 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	print_stacks(t_stack *stack)
{
	t_node *head_a;
	t_node *head_b;

	head_a = stack->head_a;
	head_b = stack->head_b;
	ft_printf("-----------------------------------\n");
	ft_printf("\tA\tB\n");
	ft_printf("-----------------------------------\n");

	while (head_a || head_b)
	{
		if (head_a)
		{
			ft_printf("\t%d", head_a->value);
			head_a = head_a->next;
		}
		else 
			ft_printf("\t");
		if (head_b)
		{
			ft_printf("\t%d", head_b->value);
			head_b = head_b->next;
		}
		ft_printf("\n");
	}
}