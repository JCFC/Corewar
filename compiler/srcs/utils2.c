/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:45 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:21:11 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_delete_cmd_lab(t_cmd *cmd, t_item *lab)
{
	t_item	*item;
	t_item	*keep;

	item = cmd->item;
	while (item)
	{
		keep = item->next;
		if (ft_strequ(item->word, lab->word))
		{
			free(item);
			cmd->item = keep;
			break ;
		}
		else if (keep && ft_strequ(keep->word, lab->word))
		{
			item->next = keep->next;
			free(keep);
			break ;
		}
		item = item->next;
	}
}

void	ft_delete_e_cmd(t_env *e, t_cmd *l)
{
	t_cmd	*tmp;
	t_cmd	*keep;

	tmp = e->cmd;
	while (tmp)
	{
		keep = tmp->next;
		if (tmp->nb == l->nb)
		{
			if (tmp->line)
				free(tmp->line);
			free(tmp);
			e->cmd = keep;
			break ;
		}
		else if (keep && keep->nb == l->nb)
		{
			tmp->next = keep->next;
			if (keep->line)
				free(keep->line);
			free(keep);
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_check_file_format(t_env *e, char *input)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (input == NULL || (len = (int)ft_strlen(input)) < 3)
		ft_strerror("%s -> wrong type | too small (champion.s needed)", input);
	else if (len > 70)
		ft_strerror("%s -> wrong type | name too long to bo accepted", input);
	else if (input[len - 1] != 's' || input[len - 2] != '.')
		ft_strerror("%s -> wrong type (file of type ' .s ' needed)", input);
	e->output = ft_strjoin(ft_strndup(input, len - 2), ".cor");
}
