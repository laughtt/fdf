/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:55:00 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/05/06 17:55:22 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <math.h>

char			*ft_strjoinfree(char *s1, const char *s2)
{
	char		*str;

	if ((s1 != NULL && s2 != NULL) && \
			(str = ft_strjoin(s1, s2)))
	{
		free(s1);
		return (str);
	}
	else
		return (NULL);
}

void			ft_transform(t_point **points, t_map *map, char type)
{
	int			width;
	int			height;

	width = 0;
	height = 0;
	while (height < map->height)
	{
		while (width < map->width)
			ft_trans(points, &width, &height, type);
		width = 0;
		height++;
	}
}

t_image			*create_image(void *mlx_ptr)
{
	t_image		*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_line, &image->endian);
	image->bpp /= 8;
	return (image);
}

void			ft_free_all(t_image *image, t_point **points, t_map *map)
{
	int		width;

	width = 0;
	while (width < map->width)
		free(points[width++]);
	free(points);
	free(image);
	free(map);
}

void			draw(t_point **points, t_map *map, char type)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*image_image;
	t_squr			square;

	square.width = 0;
	square.height = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "mlx 42");
	image_image = create_image(mlx_ptr);
	ft_transform(points, map, type);
	while (square.height < map->height - 1)
	{
		while (square.width < map->width - 1)
		{
			ft_draw_square(square, points, map, image_image);
			square.width++;
		}
		square.width = 0;
		square.height++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_image->ptr, 0, 0);
	ft_free_all(image_image, points, map);
	mlx_key_hook(win_ptr, hook_keydown, (void *)0);
	mlx_loop(mlx_ptr);
}
