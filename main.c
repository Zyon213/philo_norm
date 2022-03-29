/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:35 by yoyohann          #+#    #+#             */
/*   Updated: 2022/03/29 17:13:55 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	phi;

	if (argc != 5 && argc != 6)
		return (ft_error_message("Invalid number of argument."));
	if (ft_rules_init(&rules, argv))
		return (ft_error_message("Invalid argument."));
	if (ft_philo_init(&rules))
		return (ft_error_message("philosopher initializing."));
	if (ft_mutex_init(&rules))
		return (ft_error_message("Mutex initializing."));
	if (ft_thread_create(&rules))
		return (ft_error_message("creating thread."));
	return (0);
}
