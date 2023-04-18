/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int64.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:02 by                   #+#    #+#             */
/*   Updated: 2023/04/17 11:51:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INT64_H
# define PARSE_INT64_H

# include <stdint.h>

int64_t	parse_int64(char *str_int, char **endptr);

#endif