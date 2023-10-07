/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:05:25 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/06 22:02:35 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_matrix_len(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}