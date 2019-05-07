/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:00:41 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/05/06 18:14:46 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <math.h>

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

int				main()
{
	void 		*win_ptr;
	t_image		*image_image;
	void		*mlx_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "mlx 42");
	image_image = create_image(mlx_ptr);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_image->ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
