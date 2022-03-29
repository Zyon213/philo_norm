/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:06:35 by yoyohann          #+#    #+#             */
/*   Updated: 2022/03/29 17:11:17 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_death(t_rules *rules, t_philo *phi)
{
	int	i;

	while (!(rules->meal_count))
	{
		i = -1;
		while (++i < rules->num_philo && !(rules->died))
		{
			pthread_mutex_lock(&(rules->meal));
			if ((phi[i].time_end - ft_current_time()) > rules->time_die)
			{
				ft_display_message(rules, i, "died");
				rules->died = 1;
			}
			pthread_mutex_unlock(&(rules->meal));
			usleep(100);
		}
		if (rules->died)
			break ;
		i = 0;
		while (rules->num_eat != -1 && i < rules->num_philo
			&& phi[i].x_ate >= rules->num_eat)
			i++;
		if (i == rules->num_philo)
			rules->meal_count = 1;
	}
}

void	ft_thread_exit(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->num_philo)
		pthread_join(philo[i].thr, NULL);
	i = -1;
	while (++i < rules->num_philo)
		pthread_mutex_destroy(&(rules->fork[i]));
	pthread_mutex_destroy(&(rules->message));
}
