/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:33:07 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/14 15:15:41 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	cam_trans(int keycode, t_env *env)
{
	if (keycode == UP_ARROW_KEY)
		env->camera.vert = translate(env->camera.vert, 0,
								env->camera.xy_step, 0);
	if (keycode == DOWN_ARROW_KEY)
		env->camera.vert = translate(env->camera.vert, 0,
								-env->camera.xy_step, 0);
	if (keycode == LEFT_ARROW_KEY)
		env->camera.vert = translate(env->camera.vert,
								-env->camera.xy_step, 0, 0);
	if (keycode == RIGHT_ARROW_KEY)
		env->camera.vert = translate(env->camera.vert,
								env->camera.xy_step, 0, 0);
	if (keycode == PLUS_NUM_KEY)
		env->camera.vert = translate(env->camera.vert, 0, 0,
								-env->camera.z_step);
	if (keycode == MINUS_NUM_KEY)
		env->camera.vert = translate(env->camera.vert, 0, 0,
								env->camera.z_step);
	return (0);
}

int	cam_rotate(int keycode, t_env *env)
{
	if (keycode == W_KEY)
		env->camera.vert = rotate_about_x_center(env->camera.vert, R_STEP);
	if (keycode == S_KEY)
		env->camera.vert = rotate_about_x_center(env->camera.vert, -R_STEP);
	if (keycode == A_KEY)
		env->camera.vert = rotate_about_y_center(env->camera.vert, R_STEP);
	if (keycode == D_KEY)
		env->camera.vert = rotate_about_y_center(env->camera.vert, -R_STEP);
	if (keycode == Q_KEY)
		env->camera.vert = rotate_about_z_center(env->camera.vert, R_STEP);
	if (keycode == E_KEY)
		env->camera.vert = rotate_about_z_center(env->camera.vert, -R_STEP);
	return (0);
}
