/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:55:09 by ishyian           #+#    #+#             */
/*   Updated: 2019/07/20 18:51:15 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alum1.h"

static void		print_line(int len)
{
	int			padding;

	padding = (global()->longest_line - len) / 2;
	while (padding)
	{
		ft_putchar(' ');
		padding--;
	}
	while (len)
	{
		ft_putchar('|');
		len--;
	}
	ft_putchar('\n');
}

static void		print_lines(void)
{
	t_dllist		*curr;

	curr = global()->lines;
	while (curr)
	{
		print_line(curr->content_size);
		curr = curr->next;
	}
}

void			entern(int n)
{
	if (n >= 3)
		printf("\033[0;32mEnter number from 1 to 3\n");
	if (n == 2)
		printf("\033[0;32mEnter number from 1 to 2\n");
	if (n == 1)
		printf("\033[0;32mEnter number 1\n");
}

int				cin(void)
{
	int		n;
	char	*line;
	
	n = 0;
	get_next_line(0, &line);
	n = ft_atoi(line);
	free(line);
	return (n);
}

void			print_result(int a)
{
	if (a == 1)
		ft_printf("\033[1;36mCOM win\n");
	else
		ft_printf("You win\n");
}

void			run_game(void)
{
	int		f;
	t_dllist	*list;
	t_dllist	*del;
	int		n;

	f = 2;
	list = global()->lines;
	while (list->next)
		list = list->next;
	while (list)
	{
		ft_printf("\033[0;34mMAP\n");
		ft_printf("%d \n", list->content_size);
		print_lines();
		ft_printf("\n");
		if (f == 1)
		{
			n = ft_calc_bot();
			f = 2;
			ft_printf("\033[0;35mCOM takes %d match\n", n);
		}
		else
		{
			n = 0;
			while (n <= 0 || n > (int)list->content_size || n > 3)
			{
				entern(list->content_size);
				n = cin();
			}
			f = 1;
			ft_printf("You took %d match\n", n);
		}
		ft_printf("\n");
		list->content_size -= n;
		if (list->content_size == 0 && list->prev)
		{
			del = list;
			list = del->prev;
			free(del);
			list->next = NULL;
		}
		else if (list->content_size == 0)
		{
			free(list);
			list = NULL;
		}
	//	CLEAR;
	}
	global()->lines = NULL;
	print_result(f);
}
