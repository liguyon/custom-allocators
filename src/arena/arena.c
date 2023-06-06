/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:17:57 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 03:34:42 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocators.h"

void	arena_init(t_arena *a, void *buffer, size_t buffer_size)
{
	a->buf = buffer;
	a->buf_size = buffer_size;
	a->curr_offset = 0;
	a->prev_offset = 0;
}

void	arena_reset(t_arena *a)
{
	a->curr_offset = 0;
	a->prev_offset = 0;
}

t_tmp_arena	temp_arena_memory_begin(t_arena *a)
{
	t_tmp_arena	temp;

	temp.arena = a;
	temp.curr_offset = a->curr_offset;
	temp.prev_offset = a->prev_offset;
	return (temp);
}

void	temp_arena_memory_end(t_tmp_arena temp)
{
	temp.arena->curr_offset = temp.curr_offset;
	temp.arena->prev_offset = temp.prev_offset;
}
