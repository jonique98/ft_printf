
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_str(char *s);
void	print_hex_x(unsigned long long p, int *prit_num);
void	print_hex_X(unsigned int p, int *prit_num);
int		ft_nbr(int a);
int     ft_print_ptr(unsigned long long p);

#endif