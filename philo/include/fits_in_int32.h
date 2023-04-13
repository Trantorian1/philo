/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits_in_int32.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:33:37 by                   #+#    #+#             */
/*   Updated: 2023/04/12 13:33:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FITS_IN_INT32_H
# define FITS_IN_INT32_H

# include <stdint.h>

int32_t	fits_in_int32(char **str_int, char **endptr, int8_t sign);

#endif