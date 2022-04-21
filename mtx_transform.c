/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:17:44 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/21 15:03:49 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtx_tranform.h"

t_mtx	translation_mtx(double x, double y, double z)
{
	t_mtx	mtx;

	mtx = identity_mtx(4); //Añadir la matriz identity
	mtx.data[0][4] = x;
	mtx.data[1][4] = y;
	mtx.data[2][4] = z;
	return (mtx);
}

t_mtx	scaling_mtx(double x, double y, double z)
{
	t_mtx	mtx;

	mtx = identity_mtx(4); //Añadir la matriz identity
	mtx.data[0][0] = x;
	mtx.data[1][1] = y;
	mtx.data[2][2] = z;
	return (mtx);
}

t_mtx	shearing_mtx(double shear_arr[6])
{
	t_mtx	mtx;

	mtx = identity_mtx(4); //Añadir la matriz identity
	mtx.data[0][1] = shear_arr[0];
	mtx.data[0][2] = shear_arr[1];
	mtx.data[1][0] = shear_arr[2];
	mtx.data[1][2] = shear_arr[3];
	mtx.data[2][0] = shear_arr[4];
	mtx.data[2][1] = shear_arr[4];
	return (mtx);
}
