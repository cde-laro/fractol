/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:13:23 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/11 11:06:30 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab, size_t len)
{
	size_t		i;

	i = 0;
	while (tab[i][0] != '\0' && i <= len)
	{
		ft_putnbr(i);
		ft_putstr("\t [");
		ft_putstr(tab[i]);
		ft_putstr("]\n");
		i++;
	}
}