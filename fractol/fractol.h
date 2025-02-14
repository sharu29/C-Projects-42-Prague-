/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:11:29 by snataraj          #+#    #+#             */
/*   Updated: 2025/01/08 17:25:55 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE \
	"Enter \n\"./fractol mandelbrot\" \
	or \n\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

// Define colors with both hex and RGB
# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA 0xFF00FF       // RGB(255, 0, 255)
# define CYAN 0x00FFFF          // RGB(0, 255, 255)
# define YELLOW 0xFFFF00        // RGB(255, 255, 0)
# define NEON_GREEN 0x39FF14    // RGB(57, 255, 20)
# define NEON_PINK 0xFF6EC7     // RGB(255, 110, 199)
# define ELECTRIC_BLUE 0x00FFFF // RGB(0, 255, 255)
# define ORANGE 0xFFA500        // RGB(255, 165, 0)

/*
complex value
*/

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

/*
image
*/

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

/*
fractol ID, hooks
*/

typedef struct s_fractal
{
	char	*name;
	// mlx
	void	*mlx_connection;
	void	*mlx_window;

	// Image
	t_img	img;

	// hooks
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}			t_fractal;

/*
function prototypes
*/

void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atodbl(char *s);
void		error_msg(void);

double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			check_digit(char n);
int			float_check(char *f);

// events
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

// init
void		fractal_init(t_fractal *fractal);

// render
void		handle_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

#endif