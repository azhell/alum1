/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:45:52 by ishyian           #+#    #+#             */
/*   Updated: 2019/07/20 18:41:22 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# include <stdlib.h>
# include "../libft/libft.h"

# define CLEAR ft_putstr("\033[1J"); ft_putstr("\033[;H");

typedef struct		s_global
{
					int				fd_in;
					t_dllist		*lines;
					unsigned char	error;
					short			longest_line;
					short			count_lines;
}					t_global;

void				usage(void);
t_global			*global(void);
void				read_map(void);
void				run_game(void);
int32_t				ft_calc_bot(void);

#endif
