/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:34 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/06 03:21:19 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATORS_H
# define ALLOCATORS_H
# include <stdlib.h>

/*	Arena allocator

	A simple custom allocator that performs linear allocation.
	 The user is responsible for providing the memory and freeing it.
	
	An arena is a large, contiguous block of memory. It works by moving
	the offset everytime a part of that block is handed to the user.
*/
typedef struct s_arena		t_arena;
struct s_arena
{
	void	*buf;
	size_t	buf_size;
	size_t	prev_offset;
	size_t	curr_offset;
};
void		arena_init(t_arena *a, void *buffer, size_t buffer_size);
void		arena_reset(t_arena *a);
void		*arena_alloc(t_arena *a, size_t size);
// wth with this rule in the norm...
/*
	A temporary arena memory savepoint
	Allows for brief utilization of arena memory
	and restoration to the previously saved state.
*/
typedef struct s_tmp_arena	t_tmp_arena;
struct s_tmp_arena
{
	t_arena	*arena;
	size_t	prev_offset;
	size_t	curr_offset;
};
t_tmp_arena	temp_arena_memory_begin(t_arena *a);
void		temp_arena_memory_end(t_tmp_arena temp);

#endif