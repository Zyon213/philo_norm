/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:17:44 by yoyohann          #+#    #+#             */
/*   Updated: 2022/03/29 17:22:13 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_error_message(char *msg)
{
	int	l;

	l = ft_strlen(msg);
	write(2, "Error ", 6);
	write(2, msg, l);
	write(2, "\n", 1);
	return (1);
}

void	ft_display_message(t_rules *rules, int id, char *msg)
{
	pthread_mutex_lock(&(rules->message));
	if (!(rules->died))
	{
		printf("%lld ", ft_current_time() - rules->time_start);
		printf("%d ", id + 1);
		printf("%s\n", msg);
	}
	pthread_mutex_unlock(&(rules->message));
	return ;
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_myatoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (str[i] == '+')
		i++;
	if (ft_isnum(&str[i]))
	{
		while (str[i])
		{
			n = n * 10 + (str[i] - 48);
			i++;
		}
		if (n >= 0 && n <= 2147483647)
			return (n);
		else
			return (ft_error_message("Out of range."));
	}
	else
		return (ft_error_message("Invalid argument."));
}
