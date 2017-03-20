/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:18:55 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/11 11:42:37 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countwords(char const *s, char c)
{
	size_t		i;
	size_t		w;

	i = 0;
	w = ((s[i] != c && s[i]) ? 1 : 0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			w++;
		i++;
	}
	return (w);
}