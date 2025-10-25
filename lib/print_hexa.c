/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:52:02 by bnanque           #+#    #+#             */
/*   Updated: 2025/08/05 13:52:02 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa(unsigned int n, int upper)
{
	int		len;
	char	digit;

	len = 0;
	if (n >= 16)
		len += print_hexa(n / 16, upper);
	digit = n % 16;
	if (digit < 10)
		digit += '0';
	else
	{
		if (upper)
		digit = digit - 10 + 'A';
		else
	digit = digit - 10 + 'a';
	}
	write(1, &digit, 1);
	return (len + 1);
}
