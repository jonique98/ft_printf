/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:06:29 by josumin           #+#    #+#             */
/*   Updated: 2023/05/11 23:02:51 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
		print_num += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (*format == 'd')
		print_num += ft_nbr(va_arg(*args, int));
	else if (*format == 'i')
		print_num += ft_nbr(va_arg(*args, int));
	// else if (*format == 'u')
	// else if (*format == 'x')
	// else if (*format == 'X')
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

int main()
{
// 	// char c = 'a';
// 	// char *arr = "hi";

// 	// ft_printf("hi%c my%c name%c\n", '1', '2', c);
// 	// ft_printf("%s", arr);
	printf("%d", ft_printf(" %d ", -123));
// 	// ft_printf("This is %d hello %d", a, b);
}
