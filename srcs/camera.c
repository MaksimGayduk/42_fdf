/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:52:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/10 19:39:16 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_matrix	get_look_matrix(t_vector e, t_vector f, t_vector r, t_vector u)
{
	t_matrix m;

	m.rows = 4;
	m.cols = 4;
	m.values = create_matrix(m.rows, m.cols);
	m.values[0][0] = r.x; 
	m.values[1][0] = r.y;
	m.values[2][0] = r.z;
	m.values[0][1] = u.x;
	m.values[1][1] = u.y;
	m.values[2][1] = u.z;
	m.values[0][2] = f.x;
	m.values[1][2] = f.y;
	m.values[2][2] = f.z;
	m.values[3][0] = -e.x * r.x - e.y * r.y - e.z * r.z;
	m.values[3][1] = -e.x * u.x - e.y * u.y - e.z * u.z;
	m.values[3][2] = -e.x * f.x - e.y * f.y - e.z * f.z;
	m.values[3][3] = 1;
	return (m);
}

static t_matrix	look_at(t_vector eye, t_vector target, t_vector up_dir)
{
	t_vector forward;
	t_vector right;
	t_vector up;
	t_matrix m;

	forward = subtraction(eye, target);
	//forward = k_mult(forward, -1);
	forward = normalization(forward);
	ft_putendl("forward vector");
	print_vector(forward);
	ft_putstr("\n");
	right  = cross_production(up_dir, forward);
	right = normalization(right);
	ft_putendl("right vector");
    print_vector(right);
    ft_putstr("\n");	
	up = cross_production(forward, right);
	up = normalization(up);
    ft_putendl("up vector");
	print_vector(up);
	ft_putstr("\n");
	m = get_look_matrix(eye, forward, right, up);
	return (m);
}

void            init_camera(t_env *env)
{
    t_vector target;
    t_vector eye;
    t_vector up_dir;

    target = get_center(env->world.vert);
	ft_putendl("target vector");
    print_vector(target);
    ft_putstr("\n");
    eye = get_vector(0, 0, 5);
	ft_putendl("eye vector");
    print_vector(eye);
	ft_putstr("\n");
    up_dir = get_vector(0, 5, 0);

    env->camera.look = look_at(eye, target, up_dir);
    print_matrix(env->camera.look);
    ft_putendl("Result camera matrix");
    env->camera.vert = mult_matrix(env->world.vert, env->camera.look);
    print_matrix(env->camera.vert);
    env->camera.near = 1;
    env->camera.far = 100;
    env->camera.fov_h = DEG(90);
    env->camera.fov_v = env->camera.fov_h * SCREEN_HEIGHT / SCREEN_WIDTH;
}