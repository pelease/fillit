/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:03:51 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 21:00:57 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	unsigned char a;

	a = c;
	if (c < 0 || c > 255)
		return (c);
	if (a >= 97 && a <= 122)
		a = a - 32;
	return (a);
}