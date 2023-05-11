/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:06:29 by josumin           #+#    #+#             */
/*   Updated: 2023/05/12 04:40:00 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

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
	print_hex_x(p, &cnt);
	return (cnt);
}

void	print_nbr(unsigned int n, int *print_num)
{
	if (n > 9)
	{
		print_nbr(n / 10, print_num);
		print_nbr(n % 10, print_num);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
		*print_num += 1;
	}
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
	print_nbr(n, &print_num);
	return (print_num);
}

void	print_hex_x(unsigned long long p, int *print_num)
{
	unsigned long long			num;

	num = p % 16;
	if (p != 0)
	{
		*print_num += 1;
		print_hex_x(p / 16, print_num);
		if (num < 10)
		{
			num = num + '0';
			write(1, &num, 1);
		}
		else
		{
			num = num + 87;
			write(1, &num, 1);
		}
	}
}

void	print_hex_X(unsigned int p, int *print_num)
{
	unsigned int			num;

	num = p % 16;
	if (p != 0)
	{
		*print_num += 1;
		print_hex_X(p / 16, print_num);
		if (num < 10)
		{
			num = num + '0';
			write(1, &num, 1);
		}
		else
		{
			num = num + 55;
			write(1, &num, 1);
		}
	}
}

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

int	ft_nbr_uxX(unsigned int n, int a)
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
	if (a == 0)
		print_nbr(n, &print_num);
	else if (a == 1)
		print_hex_x(n, &print_num);
	else if (a == 2)
		print_hex_X(n, &print_num);
	return (print_num);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	format_check(const char *format, va_list *args)
{
	int	print_num;

	print_num = 0;
	if (*format == 'c')
		print_num += ft_print_char(va_arg(*args, int));
	else if (*format == 's')
		print_num += ft_print_str(va_arg(*args, char *));
	else if (*format == 'p')
		print_num += ft_print_ptr(va_arg(*args, long long));
	else if (*format == 'd')
		print_num += ft_nbr(va_arg(*args, int));
	else if (*format == 'i')
		print_num += ft_nbr(va_arg(*args, int));
	else if (*format == 'u')
		print_num += ft_nbr_uxX(va_arg(*args, unsigned int), 0);
	else if (*format == 'x')
		print_num = ft_nbr_uxX(va_arg(*args, unsigned int), 1);
	else if (*format == 'X')
		print_num = ft_nbr_uxX(va_arg(*args, unsigned int), 2);
	else if (*format == '%')
		print_num += ft_print_char('%');
	return (print_num);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_num;

	print_num = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_num += format_check(format, &args);
		}
		else
		{
			write(1, format, 1);
			print_num++;
		}
		format++;
	}
	return (print_num);
}

// int main()
// {
// 	// printf("0x%p-", (void *)ULONG_MAX);
// 	// ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	// ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	printf("%d\n", ft_printf("%u\n", 100));
// 	printf("%d\n", printf("%u\n", 100));
// }
