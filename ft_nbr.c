/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:16:32 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/11 23:07:02 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int		cnt;
	int		num;
	char	*arr;

	cnt = 0;
	num = n;
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	arr = malloc(cnt + 1);
	arr[cnt] = '\0';
	while (n != 0)
	{
		arr[--cnt] = (n % 10) + '0';
		n /= 10;
	}
	while (arr[cnt])
	{
		write(1, &arr[cnt], 1);
		cnt++;
	}
	free(arr);
	return (cnt);
}

int	ft_nbr(int n)
{
	int		i;
	int		print_num;

	i = 0;
	print_num = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{	
		write(1, "-", 1);
		n *= -1;
		print_num += 1;
	}
	print_num += print_nbr(n);
	return (print_num);
}
