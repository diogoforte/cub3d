/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/17 11:23:22 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	collision(int x, int y)
{
	printf("x: %d, y: %d\n", x, y);
	printf("map: %c\n", cub()->map->map[y + 1][x + 1]);
	return (cub()->map->map[y + 1][x + 1] == '1');
}

void	movement(void)
{
	if (cub()->player.w && !collision(((int)cub()->player.x
				+ cub()->player.delta_x) / cub()->window.tile_size,
			(int)(cub()->player.y + cub()->player.delta_y)
			/ cub()->window.tile_size))
	{
		cub()->player.x += cub()->player.delta_x;
		cub()->player.y += cub()->player.delta_y;
	}
	if (cub()->player.a && !collision((int)(cub()->player.x - 5)
			/ cub()->window.tile_size, (int)cub()->player.y
			/ cub()->window.tile_size))
		cub()->player.x -= 5;
	if (cub()->player.s && !collision(((int)cub()->player.x
				- cub()->player.delta_x) / cub()->window.tile_size,
			(int)(cub()->player.y - cub()->player.delta_y)
			/ cub()->window.tile_size))
	{
		cub()->player.x -= cub()->player.delta_x;
		cub()->player.y -= cub()->player.delta_y;
	}
	if (cub()->player.d && !collision((int)(cub()->player.x + 5)
			/ cub()->window.tile_size, (int)cub()->player.y
			/ cub()->window.tile_size))
		cub()->player.x += 5;
	if (cub()->player.q)
	{
		cub()->player.angle -= 0.1;
		if (cub()->player.angle < 0)
			cub()->player.angle += 2 * PI;
		cub()->player.delta_x = cos(cub()->player.angle) * 5;
		cub()->player.delta_y = sin(cub()->player.angle) * 5;
	}
	if (cub()->player.e)
	{
		cub()->player.angle += 0.1;
		if (cub()->player.angle > 2 * PI)
			cub()->player.angle -= 2 * PI;
		cub()->player.delta_x = cos(cub()->player.angle) * 5;
		cub()->player.delta_y = sin(cub()->player.angle) * 5;
	}
}

int	draw_game(void)
{
	cub()->move();
	cub()->draw();
	return (0);
}

t_cub	*cub(void)
{
	static t_cub cub = {
		NULL,
		NULL,
		0,
		map_add_list,
		map_load,
		exit_cub,
		maps_destroy,
		map_new,
		NULL,
		draw_menu,
		movement,
		{},
		{}
	};

	return (&cub);
}
