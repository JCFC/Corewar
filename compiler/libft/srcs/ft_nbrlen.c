/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:03:51 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 18:51:22 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int nb)
{
	int		len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}