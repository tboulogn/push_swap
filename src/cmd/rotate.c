/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:42:42 by tboulogn          #+#    #+#             */
/*   Updated: 2025/01/06 14:53:38 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	
	if (!*stack || !(*stack)->next)
		return;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	
}