/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_has.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:44:44 by                   #+#    #+#             */
/*   Updated: 2023/04/10 09:48:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BUS_HAS_H
# define ERROR_BUS_HAS_H

# include <stdbool.h>
# include "s_error_bus.h"

bool	error_bus_has(t_e_error_code error_code);

#endif
