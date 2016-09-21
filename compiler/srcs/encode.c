/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:14:12 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:50:17 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_encode2(t_cmd *cmd, t_item *item)
{
	int		i;

	i = 6;
	while (item)
	{
		if (item->type & PARAM)
		{
			if (item->type & T_REG)
				cmd->encode |= (REG_CODE << i);
			if (item->type & T_DIR)
				cmd->encode |= (DIR_CODE << i);
			if (item->type & T_IND)
				cmd->encode |= (IND_CODE << i);
			i -= 2;
		}
		item = item->next;
	}
}

void	ft_encode(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		if (item != NULL)
			ft_encode2(cmd, item);
		else
			ft_delete_e_cmd(e, cmd);
		cmd = cmd->next;
	}
}
