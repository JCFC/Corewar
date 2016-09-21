/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:15:14 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:15:17 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_file_requirements(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(REQUIREMENTS, O_RDONLY);
	if (fd < 0)
		ft_printf_fd(2, "error while trying to open %s\n", REQUIREMENTS);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	exit(0);
}

void	ft_user_man(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(USER_MAN, O_RDONLY);
	if (fd < 0)
		ft_printf_fd(2, "error while trying to open %s\n", USER_MAN);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	exit(0);
}
