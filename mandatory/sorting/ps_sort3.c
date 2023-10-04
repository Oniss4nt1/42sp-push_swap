/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:31:38 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 16:37:35 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **head, int size, t_stack *stack)
{
	int a;
	int b;
	int c;

	if (size < 3)
		return ;

	a = (*head)->value;
	b = (*head)->next->value;
	c = (*head)->next->next->value;

	if (a > b && b < c && a < c) // 2 1 3
		swap(head, 'a', stack);

	else if (a > b && b < c && a > c) // 3 1 2
		rotate(head, 'a', stack);
	else if (a < b && b > c && a > c) // 2 3 1
		reverse_rotate(head, 'a', stack);
	else if (a > b && b > c && a > c) // 3 2 1
	{
		swap(head, 'a', stack);
		reverse_rotate(head, 'a', stack);
	}
	else if (a < b && b > c && a < c) // 1 3 2
	{
		swap(head, 'a', stack);
		rotate(head, 'a', stack);
	}
}
