/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:19:49 by                   #+#    #+#             */
/*   Updated: 2023/04/10 18:38:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_CREATE_H
# define TABLE_CREATE_H

# include <stddef.h>
# include "s_table.h"

int32_t	table_init(size_t size, t_f_runner runner);

#endif
