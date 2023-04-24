/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error_code.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:24:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/22 16:52:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ERROR_CODE_H
# define E_ERROR_CODE_H

typedef enum e_error_code
{
	ERROR_NONE,
	ERROR_FORK_LEFT,
	ERROR_FORK_RIGHT,
	ERROR_THREAD_CREATE,
	ERROR_CREATE,
	E_ERRORS_SIZE
}	t_e_error_code;

#endif // !DEBUG
