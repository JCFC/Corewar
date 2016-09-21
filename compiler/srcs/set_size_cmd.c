/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:18:26 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:18:28 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_set_size_cmd2(t_item *item, t_cmd *cmd, t_env *e)
{
	t_op		op;

	if (item->type == OP)
	{
		op = ft_getop_name(item->word, e);
		cmd->size += CODESIZE_OP;
		if (op.encode)
			cmd->size += CODESIZE_ENCODE;
	}
	else if (item->type & T_REG)
		cmd->size += CODESIZE_REG;
	else if (item->type & T_IND || ((item->type & T_DIR) && op.idx))
		cmd->size += CODESIZE_IND;
	else if (item->type & T_DIR)
		cmd->size += CODESIZE_DIR;
}

void	ft_set_size_cmd(t_env *e)
{
	t_item		*item;
	t_cmd		*cmd;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			ft_set_size_cmd2(item, cmd, e);
			item = item->next;
		}
		cmd = cmd->next;
	}
}
