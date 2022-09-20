/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 14:59:59 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_element
{
		int					number;
		struct s_element	*next;
}				t_element;

typedef struct	s_liste
{
    t_element	*first;
}				t_liste;

//FT_LIST
t_liste	*init();
void	push_to_list(t_liste *liste, int value);
int		pop(t_liste *liste);
void	clear(t_liste *liste);
int		length(t_liste *liste);
void	view(t_liste *liste);


//EXIT
void	ft_exit();

//PARSING
void	parsing(char **argv, int argc);

// TREATMENT_PILE
void	treatment(char **argv, int argc, t_liste *pileA, t_liste *pileB);
void	fill_2d_pile(char **argv, int argc, t_liste *pile);
t_liste	*fill_1d_pile(int *tab_pile, int argc, t_liste *pile);

// SWAP
void	swap(t_liste *pile, int opt);
void	swap_ss(t_liste *pileA, t_liste *pileB);

// PUSH
void	push(t_liste *pileA, t_liste *pileB, int opt);

// ROTATE
void	rotate(t_liste *pile, int opt);

// UTILS
char	**delete_element_tab(char **argv, int argc, int pos);
int		*cpy_pile(t_liste *pile);

#endif