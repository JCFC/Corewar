/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:49:39 by jchen             #+#    #+#             */
/*   Updated: 2016/06/20 17:49:41 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/virtual_machine.h"
#include "../incs/corewar.h"

static void					print_plr(t_vm *vm)
{
	if ((vm->flags & VISU) != 0)
	{
		if ((vm->flags & DUMP) != 0 || (vm->flags & DUMP_M) != 0)
			dump_print_player(vm, vm->fd);
	}
	else if ((vm->flags & DUMP) == 0)
		dump_print_player(vm, STDOUT_FILENO);
	else if ((vm->flags & DUMP) != 0)
		dump_print_player(vm, vm->fd);
}

void						print_lst(t_player *lst, int fd)
{
	t_player				*cmp;

	cmp = lst;
	while (cmp != NULL)
	{
		ft_putendl_fd(cmp->name, fd);
		cmp = cmp->next;
	}
}

static void					get_status_suspend_dump(t_vm *vm)
{
	if ((vm->flags & DUMP) != 0 || (vm->flags & DUMP_M) != 0)
		print_dump(vm);
	if ((vm->flags & SUSPEND) == 0 || vm->cycle != vm->pause)
		return ;
	vm->pause += 1;
	vm->status = PAUSE;
}

static void					ft_remplace(t_vm *vm, t_player *plr)
{
	t_player				*tmp;
	t_player				*tmp_sec;

	while (plr)
	{
		tmp = plr;
		plr = plr->next;
		tmp_sec = tmp->next;
		tmp->next = tmp->prev;
		tmp->prev = tmp_sec;
	}
	vm->plr = tmp;
}

void						loop_virtual_machin(t_vm *vm)
{
	int						key;

	print_plr(vm);
	key = vm->flags & VISU ? REFRESH : 0;
	if (vm->count_pos > 1)
		ft_remplace(vm, vm->plr);
	while (1)
	{
		if (key == REFRESH)
			refrech_win(vm);
		print_info(vm);
		print_grid(vm);
		if ((key = check_key(getch(), vm)) == ESCAPE)
			break ;
		get_status_suspend_dump(vm);
		(vm->status != PAUSE) ? ft_processus(vm) : 0;
		pop_winner(vm);
		vm->cycle = vm->status != PAUSE ? vm->cycle + 1 : vm->cycle;
		vm->cycle_tmp = vm->status != PAUSE ?
			vm->cycle_tmp + 1 : vm->cycle_tmp;
	}
}
