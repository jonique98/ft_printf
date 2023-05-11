/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:16:32 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/11 22:16:56 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_nbr(int a)
{
	int		cnt;
	int		num;
	char	*arr;

	cnt = 0;
	num = a;
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	arr = malloc(cnt + 1);
	arr[cnt] = '\0';
	while (a != 0)
	{
		arr[--cnt] = (a % 10) + '0';
		a /= 10;
	}
	while (arr[cnt])
	{
		write(1, &arr[cnt], 1);
		cnt++;
	}
	free(arr);
	return (cnt);
}

int	ft_nbr(int a)
{
	int		i;
	int		print_num;

	i = 0;
	print_num = 0;
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (a < 0)
	{	
		write(1, "-", 1);
		a *= -1;
		print_num += 1;
	}
	print_num += print_nbr(a);
	return (print_num);
}