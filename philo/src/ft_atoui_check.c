/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:14:49 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/20 21:10:31 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static int	print_error(const char *str)
{
	printf("%s: this should be an unsigned int. please correct your argument\n", str);
	return (0);
}

unsigned int	ft_atoui_check(const char *str)
{
	unsigned int	nb;
	int	power;

	nb = 0;
	power = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && power < 9)
		{
			nb = (nb * 10) + (*str - 48);
			power++;
		}
		else if (power == 9 && nb == 429496729 && *str >= '0' && *str <= '5')
			nb = (nb * 10) + (*str - 48);
		else if (power == 9 && nb < 429496729 && *str >= '0' && *str <= '9')
			nb = (nb * 10) + (*str - 48);
		else
			return (print_error(str));
		str++;
	}
	return (nb);
}
