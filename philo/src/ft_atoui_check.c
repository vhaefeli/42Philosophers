/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:14:49 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/15 17:11:16 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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
		{
			write(1, "Please write the different numbers", 34);
			write(1," in correct Unsigned Int format\n", 32);
			return (0);
		}
		str++;
	}
	return (nb);
}
