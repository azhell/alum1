/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:34:42 by ishyian           #+#    #+#             */
/*   Updated: 2019/07/20 18:27:59 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alum1.h"

static void		parse_line(char *line)
{
	t_dllist		*new;

	new = ft_smalloc(sizeof(t_list));
	new->content_size = ft_atoi(line);
	new->content = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (global()->longest_line < (short)new->content_size)
		global()->longest_line = new->content_size;
	ft_dllstaddend(&global()->lines, new);
	global()->count_lines++;
}

static int		check_line(char *line)
{
	int			value;

	value = ft_atoi(line);
	if (value < 1 || value > 10000 || !ft_isnum(line))
		return (0);
	return (1);
}

void			read_map(void)
{
	char	*line;

	while (!global()->error && get_next_line(global()->fd_in, &line))
	{
		if (ft_strlen(line) < 1 && global()->lines)
			break;
		if (check_line(line))
			parse_line(line);
		else
			global()->error = 1;
		free(line);
	}
}
