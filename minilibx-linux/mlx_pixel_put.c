/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:05 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 12:28:31 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** mlx_pixel_put.c for MiniLibX in 
 ** 
 ** Made by Charlie Root
 ** Login   <ol@epitech.net>
 ** 
 ** Started on  Mon Jul 31 19:01:33 2000 Charlie Root
** Last update Tue Sep 25 17:09:49 2001 Charlie Root
 */


#include	"mlx_int.h"



int		mlx_pixel_put(t_xvar *xvar,t_win_list *win,
			      int x,int y,int color)
{
   XGCValues	xgcv;
   
   xgcv.foreground = mlx_int_get_good_color(xvar,color);
   XChangeGC(xvar->display,win->gc,GCForeground,&xgcv);
   XDrawPoint(xvar->display,win->window,win->gc,x,y);
   if (xvar->do_flush)
     XFlush(xvar->display);
}
