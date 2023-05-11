/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:19:19 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/11 22:19:20 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_str(char *s)
{
	int	i;
	int	print_num;

	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	print_num = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		print_num++;
	}
	return (print_num);
}