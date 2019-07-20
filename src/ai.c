/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:12:58 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/07/20 18:49:59 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alum1.h"

t_dllist	*ft_get_last(t_dllist *lst)
{
	t_dllist	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_remove_last(t_dllist *lst)
{
	t_dllist	*tmp;

	tmp = lst;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

int32_t	ft_ai_rm_last(int32_t count)
{
	if (count < 4)
		return (count);
	if (count == 1)
		return (1);
	if ((count - 3) % 3 == 0)
		return (1);
	else if ((count - 2) % 3 == 0)
		return (3);
	else
		return (2);
}

int32_t	ft_ai_rm(int32_t count)
{
	if (count == 1)
		return (1);
	if (count < 4 && count > 1)
		return (count - 1);
	if ((count - 3) % 3 == 0)
		return (3);
	else if ((count - 2) % 3 == 0)
		return (1);
	else
		return (2);
}

int32_t	ft_calc_bot()
{
	t_dllist	*lst;

	lst = global()->lines;
	lst = ft_get_last(lst);
	if ((global()->count_lines % 2) == 0 || global()->count_lines == 1)
		return (ft_ai_rm(lst->content_size));
	else
		return (ft_ai_rm_last(lst->content_size));
	return(0);
}
