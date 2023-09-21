/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:04:15 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/21 16:47:40 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/include/libft.h"
# include <stdlib.h>


//############################# Macros #########################################

#define SA "sa\n";
#define SB "sb\n";
#define SS "ss\n";
#define PA "pa\n";
#define PB "pb\n";
#define RA "ra\n";
#define RB "rb\n";
#define RR "rr\n";
#define RRA "rra\n";
#define RRB "rrb\n";
#define RRR "rrr\n";

//############################# Structures #####################################

typedef enum e_bool
{
	is_false,
	is_true
}				t_bool;

typedef struct s_node
{
	int		value;
	struct s_node *next;
}				t_node;

typedef struct s_stack
{
	int	size_a;
	int size_b;
	int min_a;
	int min_b;
	int max_a;
	int max_b;
	t_node *head_a;
	t_node *head_b;
}			t_stack;


//############################# Prototypes #####################################
//############################# INIT ###########################################

t_stack	*init_stack(void);
t_node	*init_node(int value);
void add_to_list(t_node **head, t_stack *stack, int value);
void	add_to_head(t_node **head, int value);

//############################# CHECK ##########################################

t_bool is_integer(char *str);
t_bool is_duplicate(t_node *head);
int *split_and_convert(char *str);
t_bool check_value(char *str);
t_bool	process_arguments(t_stack *stack, int argc, char **argv);
t_bool	is_sorted(t_node *head);

//############################# MEM FREE #######################################

void	free_list(t_node *head);
void	free_stack(t_stack *stack);

//############################# OPERATIONS #####################################

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rr(t_stack *stack);

# endif