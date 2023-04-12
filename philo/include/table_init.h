/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:19:49 by                   #+#    #+#             */
/*   Updated: 2023/04/11 19:23:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_CREATE_H
# define TABLE_CREATE_H

# include <stddef.h>
# include <stdint.h>

# include "s_table.h"

int32_t	table_init(size_t size, t_f_runner runner);

#endif
