/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:11:19 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:49:24 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_getbin(int val, int nb_octet)
{
	char	buffer[nb_octet];
	int		i;
	int		nb;

	i = 0;
	nb = nb_octet;
	while (nb--)
	{
		buffer[nb] = (char)((val >> i) & 0xFF);
		i += 8;
	}
	return ((char *)ft_memdup(buffer, nb_octet));
}

int		ft_addbin(t_cmd *cmd, int size, int code, int codesize)
{
	char	**bin;
	char	*c_bin;

	bin = &(cmd->bin);
	c_bin = ft_getbin(code, codesize);
	if ((*bin = (char*)ft_memjoin(*bin, size, c_bin, codesize)) == NULL)
		ft_strerror("error binary creation", "");
	return (size + codesize);
}

int		ft_binary_creation2(int size, t_item *item, t_env *e, t_cmd *cmd)
{
	t_op	op;

	if (item->type == OP)
	{
		op = ft_getop_name(item->word, e);
		size = ft_addbin(cmd, size, item->code, CODESIZE_OP);
		if (op.encode)
			size = ft_addbin(cmd, size, cmd->encode, CODESIZE_ENCODE);
	}
	else if (item->type & T_REG)
		size = ft_addbin(cmd, size, item->code, 1);
	else if (item->type & T_IND || ((item->type & T_DIR) && op.idx))
		size = ft_addbin(cmd, size, item->code, CODESIZE_IND);
	else if (item->type & T_DIR)
		size = ft_addbin(cmd, size, item->code, CODESIZE_DIR);
	return (size);
}

void	ft_binary_creation(t_env *e)
{
	t_item	*item;
	t_cmd	*cmd;
	int		size;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		size = 0;
		while (item)
		{
			size = ft_binary_creation2(size, item, e, cmd);
			item = item->next;
		}
		cmd = cmd->next;
	}
}
