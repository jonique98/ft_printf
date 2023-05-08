/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:06:29 by josumin           #+#    #+#             */
/*   Updated: 2023/05/09 02:00:29 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include<stdio.h>
// #include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int print_num;

	i = 0;
	print_num = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		s++;
		print_num++;
	}
	return (print_num);
}

int ft_putpointer(unsigned long long p)
{
	char *ten = "0123456789abcdef";
	while (p != 0)
	{
		write(1, &ten[p % 16], 1);
		p = p / 10;
	}
	return (0);
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
	// else if (*format == 'd')
	// else if (*format == 'i')
	// else if (*format == 'u')
	// else if (*format == 'x')
	// else if (*format == 'X')
	// else if (*format == '%')
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
			write(1, format, 1);
		format++;
	}
	return (print_num);
}


int main()
{
	char c = 'a';
	char *arr = "hi";

	// ft_printf("hi%c my%c name%c\n", '1', '2', c);
	// ft_printf("%s", arr);
	ft_printf("%p", arr);
	// ft_printf("This is %d hello %d", a, b);
}