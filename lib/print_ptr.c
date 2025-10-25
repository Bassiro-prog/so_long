/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:56:56 by bnanque           #+#    #+#             */
/*   Updated: 2025/08/05 13:56:56 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(void *ptr)
{
	unsigned long	n;
	char			*hex;
	int				len;
	int				i;
	char			buffer[16];

	i = 0;
	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	n = (unsigned long)ptr;
	hex = "0123456789abcdef";
	len += print_str("0x");
	if (n == 0)
		return (len + print_char('0'));
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
		len += print_char(buffer[i]);
	return (len);
}
