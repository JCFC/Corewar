/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:16:51 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:17:25 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_remove_useless_lines(t_env *e)
{
	t_cmd			*tmp;
	t_cmd			*keep;

	tmp = e->cmd;
	while (tmp)
	{
		keep = tmp->next;
		if ((tmp->line == NULL || ft_isuselessstr(tmp->line)))
			ft_delete_e_cmd(e, tmp);
		tmp = tmp->next;
	}
}

char	*ft_format_str(char *str, int line_nb)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		if ((int)ft_strlen(str) > LINE_LENGHT)
			ft_interror("(Norme) the line %d is too long", line_nb);
		while (str[i])
		{
			if (str[i] == COMMENT_CHAR || str[i] == COMMENT_CHAR_2)
			{
				str[i] = '\0';
				break ;
			}
			i++;
		}
	}
	return (str);
}

t_cmd	*ft_create_cmd(char *line, int i)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd))))
		ft_strerror("[ft_create_line] malloc cmd", "");
	cmd->line = ft_strdup(ft_format_str(line, i));
	cmd->nb = i;
	cmd->size = 0;
	cmd->encode = 0;
	cmd->bin = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	ft_push_line(t_env *e, char *line, int i)
{
	t_cmd	*to_add;
	t_cmd	*l;

	to_add = ft_create_cmd(line, i);
	if (to_add)
	{
		l = e->cmd;
		if (l)
		{
			while (l->next)
				l = l->next;
			l->next = to_add;
		}
		else
			e->cmd = to_add;
	}
}

void	ft_read_file(char *av, t_env *e)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	i = 1;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_strerror("file \"%s\" does not exists", av);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_push_line(e, line, i);
		i++;
		free(line);
	}
	if (ret == -1)
		ft_strerror("an issue occured when tried to open %s", av);
	if (i <= 1 || ft_line_count(e) <= 0)
		ft_strerror("File %s is empty", av);
	ft_remove_useless_lines(e);
}
