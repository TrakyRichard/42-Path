/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:42:13 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/17 07:23:10 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_int_or_char(const char *c)
{
	return (*c == 'i' || c == 'c');
}

int is_dec(const char *c)
{
	return (*c == 'd');
}

int	is_pointer(const char *c)
{
	return (*c == 'p');
}

int	is_hexadecimal(const char *c)
{
	return (*c == 'p');
}
