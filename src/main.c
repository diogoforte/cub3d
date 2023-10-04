/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:35 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 01:14:04 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (help_message(1));
	engine()->start = &engine_start;
	engine()->start();
	map_loader(av);
	sleep(15);
	engine()->free();
}
