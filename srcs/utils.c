/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:34:31 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/19 13:41:56 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**delete_element_tab(char **argv, int argc, int pos)
{
	int i;

	i = pos;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argv);
}

int	*cpy_pile(t_pile *pile)
{
	int length_pile;
	int	*tab_pile;
	int	i;

	length_pile = length(pile);
	tab_pile = malloc(sizeof(int) * length_pile);
	i = 0;
	while (i < length_pile)
	{
		tab_pile[i] = pile->nombre;
		pile = pile->prec;
		i++;
	}
	return (tab_pile);
}