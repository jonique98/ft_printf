/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:18:33 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/11 23:03:13 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long long p)
{
	unsigned long long	num;
	char				*arr;

	arr = "0123456789abcdef";
	num = p % 16;
	if (p != 0)
	{
		print_hex(p / 16);
		write(1, &arr[num], 1);
	}
}
