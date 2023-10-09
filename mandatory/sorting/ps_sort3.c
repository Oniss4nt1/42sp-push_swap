/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:31:38 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 15:35:52 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: sort_three
 * -----------------
 * This function sorts a list of 3 numbers. It first checks if the list is
 * already sorted, if it is, it returns. If it is not, it checks the possible
 * combinations of the numbers and swaps or rotates them accordingly.
 * 
 * @param: **head: pointer to the head of the list.
 * @param: size: size of the list.
 * @var: a, b, c: values of the first, second and third node of the list.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	sort_three(t_node **head, int size)
{
	int	a;
	int	b;
	int	c;

	if (size < 3)
		return ;
	a = (*head)->value;
	b = (*head)->next->value;
	c = (*head)->next->next->value;
	if (a > b && b < c && a < c)
		swap(head, 'a');
	else if (a > b && b < c && a > c)
		rotate(head, 'a');
	else if (a < b && b > c && a > c)
		reverse_rotate(head, 'a');
	else if (a > b && b > c && a > c)
	{
		swap(head, 'a');
		reverse_rotate(head, 'a');
	}
	else if (a < b && b > c && a < c)
	{
		swap(head, 'a');
		rotate(head, 'a');
	}
}
