/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:04:15 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 18:41:25 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>

//############################# Macros #########################################

# define INT_MIN -2147483648
# define INT_MAX 2147483647

//############################# Structures #####################################

typedef enum e_bool
{
	is_false,
	is_true
}					t_bool;

typedef struct s_numbers
{
	int				*num;
	int				size;
}					t_numbers;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size_a;
	int				size_b;
	int				moves;
	t_node			*head_a;
	t_node			*head_b;
}					t_stack;

//############################# Prototypes #####################################
//############################# INIT ###########################################

t_stack			*init_stack(void);
t_node			*init_node(int value);
t_numbers		init_numbers(void);
void			add_to_list(t_node **head, t_stack *stack, int value);
void			add_to_head(t_node **head, int value);

//############################# CHECK ##########################################

t_bool			is_integer(char *str);
t_bool			is_duplicate(t_node *head);
t_numbers		split_args(char *str);
t_bool			check_value(char *str);
t_bool			process_arguments(t_stack *stack, int argc, char **argv);
t_bool			is_sorted(t_node *head);

//############################# MEM FREE #######################################

void			free_list(t_node *head);
void			free_stack(t_stack *stack);
void			free_error(t_stack *stack, t_numbers *array, char **str, int i);

//############################# OPERATIONS #####################################

void			swap(t_node **head, char move);
void			double_swap(t_stack *stack);
void			rotate(t_node **head, char move);
void			double_rotate(t_stack *stack);
void			push_a_to_b(t_stack *stack);
void			push_b_to_a(t_stack *stack);
void			reverse_rotate(t_node **head, char move);
void			double_reverse_rr(t_stack *stack);

//############################# SORT ###########################################

void			sort_three(t_node **head, int size);
void			sort_short(t_stack *stack);
void			sorting(t_stack *stack, int argc);

//############################# UTILS ##########################################

void			move_min_top(t_stack *stack);
void			sort_index(t_stack *stack);
void			radix_sort(t_stack *stack);

//############################# DEBUG ##########################################

void			print_stacks(t_stack *stack);
void			print_list(t_node *head);

#endif