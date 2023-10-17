/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:57 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/17 14:43:37 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *str, t_map *map)
{
	if (map)
	{
		free(map->error);
		map->error = ft_strdup(str);
		map->playable = false;
	}
	cub()->status = 1;
	return (1);
}

int	exit_cub(char *str)
{
	cub()->maps_destroy();
	if (cub()->window.win)
		mlx_destroy_window(cub()->window.mlx, cub()->window.win);
	if (cub()->window.img.img)
		mlx_destroy_image(cub()->window.mlx, cub()->window.img.img);
	if (cub()->window.mlx)
	{
		mlx_destroy_display(cub()->window.mlx);
		free(cub()->window.mlx);
	}
	if (str)
		exit(err(str, NULL));
	else
		exit(cub()->status);
	return (0);
}

void	maps_destroy(void)
{
	t_map	*tmp;
	t_map	*map;

	map = cub()->maps;
	while (map)
	{
		tmp = map->next;
		map->destroy_map(map);
		map->destroy_error(map);
		map->destroy_cords(map);
		if (map)
			free(map);
		map = tmp;
	}
	map = NULL;
}
