/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:19:25 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/20 14:23:39 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

typedef struct s_arena		t_arena;
struct s_arena
{
	void	*buf;
	size_t	buf_size;
	size_t	prev_offset;
	size_t	curr_offset;
};
void		*arena_new(size_t buffer_size);
void		arena_reset(t_arena *a);
void		*arena_alloc(t_arena *a, size_t size);
void		arena_destroy(t_arena *a);

#endif