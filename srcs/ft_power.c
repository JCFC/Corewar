/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:47:32 by jchen             #+#    #+#             */
/*   Updated: 2016/06/20 17:47:36 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

int							ft_power(int power, int nb)
{
	int						i;
	int						tmp;

	tmp = nb;
	if (power == 0)
		return (1);
	i = 0;
	while (i < power)
	{
		tmp *= nb;
		i++;
	}
	return (tmp);
}