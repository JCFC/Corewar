/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:16:34 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:51:50 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_name(char *s, t_env *e, int j, int i)
{
	int		i2;

	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '"')
		ft_slc_error("header name need to be in quotes", s + i, j, i);
	i++;
	i2 = i;
	while (s[i2] && s[i2] != '"')
		i2++;
	if (s[i2] != '"')
		ft_slc_error("name need quotes", ft_strndup(s + i, i2 - i), j, i2);
	else if (i > i2 || (i2 - i) < NAME_LENGHT_MIN)
		ft_slc_error("header name too short", ft_strndup(s + i, i2 - i), j, i2);
	else if ((i2 - i) > PROG_NAME_LENGTH)
		ft_slc_error("header name too long", ft_strndup(s + i, i2 - i), j, i2);
	e->name = ft_strndup(s + i, i2 - i);
	while (s[i2++])
		if (s[i2] != ' ' && s[i2] != '\t' && s[i2] != '\0')
			ft_clc_error("unexpected char \'%c\' after name", s[i2], j, i2);
	e->name_ok = 1;
}

void	ft_check_comment(char *s, t_env *e, int j, int i)
{
	int		i2;

	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '"')
		ft_slc_error("header comment need to be in quotes", s + i, j, i);
	i++;
	i2 = i;
	while (s[i2] && s[i2] != '"')
		i2++;
	if (s[i2] != '"')
		ft_slc_error("comment need quotes", ft_strndup(s + i, i2 - i), j, i2);
	else if (i > i2 || (i2 - i) < COMMENT_LENGHT_MIN)
		ft_slc_error("comment too short", ft_strndup(s + i, i2 - i), j, i2);
	else if ((i2 - i) > COMMENT_LENGTH)
		ft_slc_error("comment too long", ft_strndup(s + i, i2 - i), j, i2);
	e->comment = ft_strndup(s + i, i2 - i);
	while (s[i2++])
		if (s[i2] != ' ' && s[i2] != '\t' && s[i2] != '\0')
			ft_clc_error("unexpected char \'%c\' after comment", s[i2], j, i2);
	e->comment_ok = 1;
}

void	ft_delete_cmd_name_comment(t_env *e)
{
	t_cmd	*tmp;

	tmp = e->cmd;
	e->cmd = tmp->next;
	ft_delete_e_cmd(e, tmp);
	tmp = e->cmd;
	e->cmd = tmp->next;
	ft_delete_e_cmd(e, tmp);
}

void	ft_parse_header2(t_env *e)
{
	t_cmd	*tmp;
	int		count;
	int		i;

	count = 0;
	i = 0;
	tmp = e->cmd;
	if (!e->name_ok || !e->comment_ok)
		ft_strerror("header format. %s can't be generated.", e->output);
	while (e->name[i++])
		if (e->name[i] != ' ' && e->name[i] != '\t')
			count++;
	if (count < NAME_LENGHT_MIN)
		ft_strerror("name to short. %s can't be generated.", e->output);
	count = 0;
	i = 0;
	while (e->comment[i++])
		if (e->comment[i] != ' ' && e->comment[i] != '\t')
			count++;
	if (count < COMMENT_LENGHT_MIN)
		ft_strerror("comment to short. %s can't be generated.", e->output);
	ft_delete_cmd_name_comment(e);
}

void	ft_parse_header(t_env *e)
{
	t_cmd	*tmp;
	int		i;
	char	*str;

	i = 0;
	tmp = e->cmd;
	str = tmp->line;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (ft_strnequ(str + i, NAME_CMD_STRING, 4))
		ft_check_name(str + i, e, tmp->nb, 5);
	else
		ft_strerror("header name format -> %s can't be generated", e->output);
	tmp = tmp->next;
	str = tmp->line;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (ft_strnequ(str + i, COMMENT_CMD_STRING, 7))
		ft_check_comment(str + i, e, tmp->nb, 8);
	else
		ft_strerror("header comment format. %s can't be generated", e->output);
	ft_parse_header2(e);
}
