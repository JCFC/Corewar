/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_code_op_and_num_param.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:18:04 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:18:12 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_set_code_to_op_and_num_param(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;
	t_op	op;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			if (item->type == OP)
			{
				op = ft_getop_name(item->word, e);
				if (ft_strequ(item->word, op.name))
					item->code = op.opcode;
			}
			else if ((item->type & PARAM) == PARAM)
				if ((item->type & T_REG) == T_REG || !(item->type & T_LAB))
					item->code = ft_atoi(item->word);
			item = item->next;
		}
		cmd = cmd->next;
	}
}
