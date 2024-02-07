/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:01:27 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 17:08:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*joined_str;

	str1_len = 0;
	str2_len = 0;
	if (str1 != NULL)
		str1_len = ft_strlen(str1);
	if (str2 != NULL)
		str2_len = ft_strlen(str2);
	joined_str = (char *)malloc(sizeof(char) * (str1_len + str2_len + 1));
	if (!joined_str)
		return (NULL);
	if (str1 != NULL)
		ft_memcpy(joined_str, str1, str1_len);
	if (str2 != NULL)
		ft_memcpy(joined_str + str1_len, str2, str2_len);
	joined_str[str1_len + str2_len] = '\0';
	return (joined_str);
	free(joined_str);
}
