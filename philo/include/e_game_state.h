/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_game_state.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:11:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 18:17:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_GAME_STATE_H
# define E_GAME_STATE_H

typedef enum e_game_state
{
	IDLE,
	SYNCHRONISED,
	END
}	t_e_game_state;

#endif // !E_GAME_STATE_H
