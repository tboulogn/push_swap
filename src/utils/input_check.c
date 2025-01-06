/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:04:10 by tboulogn          #+#    #+#             */
/*   Updated: 2025/01/06 18:10:14 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);	
}

static int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[1])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);	
}

static int	is_zero(char *av)
{
	int i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zero;
	
	nb_zero = 0;
	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		nb_zero += is_zero(av[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (is_duplicate(av))
		return (0);
	return (1);
}