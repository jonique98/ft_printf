/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:17:55 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/11 22:57:51 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long p)
{
	int	cnt;

	cnt = 0;
	write(1, "0x", 2);
	cnt += 2;
	if (p == 0)
	{
		write(1, "0", 1);
		return (cnt + 1);
	}
	print_hex(p);
	while (p != 0)
	{
		p /= 16;
		cnt++;
	}
	return (cnt);
}
