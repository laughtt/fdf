/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:30:01 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/05/06 18:10:46 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H
# include "miniLibX/mlx.h"
# include "libft/libft.h"
# define IMG_WIDTH 2000
# define IMG_HEIGHT 2000
# define SQUARE_SIZE 20
# define STR_POINT 100
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}					t_image;

#endif
