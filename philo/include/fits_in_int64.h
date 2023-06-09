/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits_in_int64.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:57:39 by                   #+#    #+#             */
/*   Updated: 2023/04/17 11:57:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FITS_IN_INT64_H
# define FITS_IN_INT64_H

# include <stdint.h>

int64_t	fits_in_int64(char *str_int, char **endptr, int8_t sign);

#endif
