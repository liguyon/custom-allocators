/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:34 by liguyon           #+#    #+#             */
/*   Updated: 2023/06/20 14:25:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATORS_H
# define ALLOCATORS_H
# include <stdlib.h>

/*
	Arena allocator, a simple custom allocator that performs linear allocation.
	
	An arena is a large, contiguous block of memory. It works by moving
	the offset everytime a part of that block is handed to the user.
*/
void	*arena_init(size_t buffer_size);
void	arena_reset(void *arena);
void	*arena_alloc(void *arena, size_t size);
void	arena_destroy(void *arena);

#endif