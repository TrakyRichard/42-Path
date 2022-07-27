/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:00:53 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/17 07:19:40 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

typedef struct printf_struct
{
	int		i;
	double	d;
	char	*s;
}	t_printf_struct;

int	ft_printf(const char *fm, ...)
{
	va_list			args;
	t_printf_struct	placeholder;

	va_start(args, fm);
	while (*fm != '\0')
	{
		if ((char) *fm == '%')
		{
			if (is_int_or_char(*(fm + 1)))
			{
				placeholder.i = va_arg(args, int);
				ft_putchar_fd(placeholder.i, 1);
			}

		}

		ft_putchar_fd(*fm, 1);
		fm++;
	}
	return (0);
}
