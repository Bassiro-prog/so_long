/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:55:20 by bnanque           #+#    #+#             */
/*   Updated: 2025/08/05 13:55:20 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_nbr(int n)
{
	char	digit;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}
	if (n > 9)
	{
		len += print_nbr(n / 10);
		len += print_nbr(n % 10);
	}
	else
	{
		digit = n + '0';
		len += write(1, &digit, 1);
	}
	return (len);
}
