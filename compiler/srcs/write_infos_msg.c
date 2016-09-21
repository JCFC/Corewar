/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infos_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:20:23 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 14:04:14 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_message(t_env *e)
{
	ft_printf("asm: file {green}%s{eoc} created\n", e->output);
}

void	ft_print_infos(t_env *e)
{
	if (g_flag_i)
	{
		ft_printf("Informations about {green}%s{eoc}\n\n", e->output);
		if (e->new_name)
		{
			ft_printf("{yellow}Old name: {eoc}%s\n", e->name);
			ft_printf("{yellow}New name: {eoc}%s\n", e->header.prog_name);
		}
		else
			ft_printf("{yellow}Name:     {eoc}%s\n", e->header.prog_name);
		ft_printf("{yellow}Comment:  {eoc}%s\n", e->header.comment);
		ft_printf("{yellow}Size:     {eoc}%d bytes\n",
							ft_reverse(e->header.prog_size));
		ft_printf("{yellow}Magic:    {eoc}%s\n\n",
							ft_itoa_base(COREWAR_EXEC_MAGIC, 16));
	}
}

void	ft_write_outfile(t_env *e)
{
	int		fd;
	t_cmd	*cmd;

	fd = open(e->output, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
		ft_strerror("%s file out error", e->output);
	cmd = e->cmd;
	write(fd, (char*)&(e->header), sizeof(e->header));
	while (cmd)
	{
		write(fd, cmd->bin, cmd->size);
		cmd = cmd->next;
	}
}
