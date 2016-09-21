/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:17:34 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:17:38 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_line_count(t_env *e)
{
	int		count;
	t_cmd	*cmd;

	cmd = e->cmd;
	count = 0;
	while (cmd)
	{
		if (cmd->line)
			count++;
		cmd = cmd->next;
	}
	return (count);
}
