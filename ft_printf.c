/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:06:29 by josumin           #+#    #+#             */
/*   Updated: 2023/05/09 19:35:44 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

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

char	*ft_itoa(int a)
{
	int		cnt;
	int		num;
	char	*arr;

	cnt = 0;
	if (a < 0)
		a *= -1;
	num = a;
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	arr = malloc(cnt + 1);
	arr[cnt] = '\0';
	while (--cnt >= 0)
	{
		arr[cnt] = (a % 10) + '0';
		a /= 10;
	}
	return (arr);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
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

int	ft_putpointer(unsigned long long p)
{
	int	cnt;

	if (p == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	cnt = 0;
	print_hex(p);
	while (p != 0)
	{
		p /= 16;
		cnt++;
	}
	return (cnt);
}

int	ft_putnbr(int a)
{
	int		i;
	char	*arr;
	int		print_num;

	i = 0;
	print_num = 0;
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (a < 0)
	{
		write(1, "-", 1);
		print_num++;
	}
	arr = ft_itoa(a);
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
		print_num++;
	}
	free(arr);
	return (print_num);
}

int	format_check(const char *format, va_list *args)
{
	int	print_num;

	print_num = 0;
	if (*format == 'c')
		print_num += ft_putchar(va_arg(*args, int));
	else if (*format == 's')
		print_num += ft_putstr(va_arg(*args, char *));
	else if (*format == 'p')
		print_num += ft_putpointer(va_arg(*args, unsigned long long));
	else if (*format == 'd')
		print_num += ft_putnbr(va_arg(*args, int));
	// else if (*format == 'i')
	// else if (*format == 'u')
	// else if (*format == 'x')
	// else if (*format == 'X')
	else if (*format == '%')
	{
		write(1, "%", 1);
		print_num++;
	}
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
// // 	// char c = 'a';
// // 	// char *arr = "hi";

// // 	// ft_printf("hi%c my%c name%c\n", '1', '2', c);
// // 	// ft_printf("%s", arr);
// 	ft_printf("%d", -123);
// // 	// ft_printf("This is %d hello %d", a, b);
// }
