/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:16:01 by daltman           #+#    #+#             */
/*   Updated: 2016/06/21 11:16:23 by daltman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_parse(t_env *e)
{
	ft_parse_header(e);
	(g_flag_d == 1) ? ft_debug0(e) : ft_nodebug(e);
	ft_store_items(e);
	(g_flag_d == 1) ? ft_debug1(e) : ft_nodebug(e);
	ft_check_item_after_storage(e);
	ft_check_param_type_per_op(e);
	ft_set_code_to_op_and_num_param(e);
	(g_flag_d == 1) ? ft_debug2(e) : ft_nodebug(e);
	ft_set_size_cmd(e);
	ft_set_addr_and_header(e);
	(g_flag_d == 1) ? ft_debug3(e) : ft_nodebug(e);
	ft_set_labels_addr(e);
	(g_flag_d == 1) ? ft_debug4(e) : ft_nodebug(e);
	ft_filter_remove_labels(e);
	(g_flag_d || g_flag_c) ? ft_debug5(e) : ft_nodebug(e);
	ft_encode(e);
	(g_flag_k == 1) ? ft_debug6(e) : ft_nodebug(e);
	ft_binary_creation(e);
	(g_flag_b == 1) ? ft_debug7(e) : ft_nodebug(e);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		ac_nb;

	ac_nb = 1;
	ft_init_gflags();
	ft_init_env(&e);
	if (ac > 1)
	{
		ft_flags(ac, av, &ac_nb, &e);
		if (ac_nb > ac || !av[ac_nb])
			ft_strerror("no input file", "..");
		ft_check_file_format(&e, av[ac_nb]);
		ft_read_file(av[ac_nb], &e);
		ft_parse(&e);
		ft_write_outfile(&e);
		ft_print_infos(&e);
		ft_print_message(&e);
	}
	else
		ft_printf_fd(2, "{red}asm: error: no input file\n\tuse ./asm -h\n");
	return (0);
}
