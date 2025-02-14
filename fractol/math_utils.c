/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 12:11:46 by snataraj          #+#    #+#             */
/*   Updated: 2024-10-18 12:11:46 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	check_digit(char n)
{
	return (n >= '0' && n <= '9');
}

int	float_check(char *f)
{
	int	count;

	count = 0;
	if (*f == '-' || *f == '+')
		f++;
	while (*f)
	{
		if (*f == '.')
		{
			if (count > 0)
				return (0);
			count++;
		}
		else if (!check_digit(*f))
			return (0);
		f++;
	}
	return (1);
}
