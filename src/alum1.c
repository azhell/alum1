/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:46:19 by ishyian           #+#    #+#             */
/*   Updated: 2019/07/20 18:17:13 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../inc/alum1.h"

static void	open_file(char *filename)
{
	global()->fd_in = open(filename, O_RDONLY);
	if (read(global()->fd_in, NULL, 0) < 0)
		global()->error = 1;
}

int			main(int argc, char **argv)
{
	ft_bzero(global(), sizeof(t_global));
	if (argc > 2)
		usage();
	else if (argc == 2)
		open_file(argv[1]);
	else
		global()->fd_in = 1;
	if (!global()->error)
		read_map();
	CLEAR;
	if (!global()->error)
		run_game();
	if (global()->error)
		ft_printf("ERROR\n");
	if (global()->lines != NULL)
	ft_dllstdel(&global()->lines, &ft_memsdel);
	return (0);
}
