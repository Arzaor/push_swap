/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:13:44 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/10 10:33:45 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*init()
{
    t_liste		*liste;
    t_element	*element;

	liste = malloc(sizeof(*liste));
	element = malloc(sizeof(*element));
    if (liste == NULL || element == NULL)
        exit(EXIT_FAILURE);
    element->number = 0;
    element->next = NULL;
    liste->first = element;
    return liste;
}

void push_to_list(t_liste *liste, int value)
{
    t_element *new;

	new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
        exit(EXIT_FAILURE);
    new->number = value;
	new->group = 0;
    new->next = liste->first;
    liste->first = new;
}

int	pop(t_liste *liste)
{
    t_element	*element;
	int			value;

	element = NULL;
	value = 0;
    if (liste == NULL)
        exit(EXIT_FAILURE);
    if (liste->first != NULL)
    {
		element = liste->first;
		value = liste->first->number;
        liste->first = liste->first->next;
        free(element);
    }
	return (value);
}

void	clear(t_liste *liste)
{
    t_element	*now;

	now = NULL;
    if (liste == NULL)
        exit(EXIT_FAILURE);
    while (liste->first != NULL)
    {
		now = liste->first;
		liste->first = liste->first->next;
		free(now);
    }
}

int	length_by_group(t_liste *liste, int group)
{
    t_element	*now;
	int			n;

	now = NULL;
	n = 0;
    if (liste == NULL)
        exit(EXIT_FAILURE);
	now = liste->first;
    while (now->next != NULL)
    {
		if (now->group == group)
			n++;
        now = now->next;
    }
	return (n);
}


int	length(t_liste *liste)
{
    t_element	*now;
	int			n;

	now = NULL;
	n = 0;
    if (liste == NULL)
        exit(EXIT_FAILURE);
	now = liste->first;
    while (now->next != NULL)
    {
		n++;
        now = now->next;
    }
	return (n);
}

void	view(t_liste *liste)
{
    t_element *now;

	now = NULL;
    if (liste == NULL)
        exit(EXIT_FAILURE);
	now = liste->first;
    while (now->next != NULL)
    {
        printf("%d dans le groupe %d\n", now->number, now->group);
        now = now->next;
    }
}

int		search_max(t_liste *pile, int number)
{
	t_element *now;
	int	position;

	now = pile->first;
	position = 0;
    while (now->next != NULL)
    {
		if (now->number == number)
			break ;
		position++;
        now = now->next;
    }
	return (position);
}