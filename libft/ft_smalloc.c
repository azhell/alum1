/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:16:27 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 23:49:23 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_smalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p)
		return (p);
	ft_putstr("Memory Allocation failure.\n");
	exit(0);
}
