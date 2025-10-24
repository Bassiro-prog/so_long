/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:18:11 by bnanque           #+#    #+#             */
/*   Updated: 2025/08/05 14:18:11 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(unsigned int n)
{
	int		len;
	char	digit;

	len = 0;
	if (n >= 10)
	{
		len += print_unsigned(n / 10);
		len += print_unsigned(n % 10);
	}
	else
	{
		digit = n + '0';
		len += write(1, &digit, 1);
	}
	return (len);
}
