/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_create.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:19:49 by                   #+#    #+#             */
/*   Updated: 2023/04/10 15:19:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_CREATE_H
# define TABLE_CREATE_H

# include <stddef.h>
# include "s_table.h"

t_s_table	*table_create(size_t size, t_f_runner runner);

#endif
