/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:14:08 by yoyohann          #+#    #+#             */
/*   Updated: 2022/03/29 17:17:30 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_current_time(void)
{
	struct timeval	tv;
	long long		ct;

	gettimeofday(&tv, NULL);
	ct = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ct);
}

void	ft_sleep(t_rules *rules, long long rest)
{
	long long	ct;

	ct = ft_current_time();
	while (!(rules->died))
	{
		if ((ft_current_time() - ct) >= rest)
			break ;
		usleep(50);
	}
}
