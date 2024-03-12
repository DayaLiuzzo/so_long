/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:32:38 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/01/09 17:49:40 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include<stdlib.h>

char	*join(char const *ss1, char const *ss2, char *ffullbish)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ss1[i])
	{
		ffullbish[i] = ss1[i];
		i++;
	}
	while (ss2[j])
	{
		ffullbish[i] = ss2[j];
		i++;
		j++;
	}
	ffullbish[i] = '\0';
	return (ffullbish);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fullbish;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	fullbish = (char *)malloc((j + i + 1) * sizeof(char));
	if (fullbish == NULL)
		return (NULL);
	fullbish = join(s1, s2, fullbish);
	return (fullbish);
}
/*
int main()
{
    // Test the ft_strjoin function
    const char *s1 = "Hello, ";
    const char *s2 = "World!";

    char *result = ft_strjoin(s1, s2);

    if (result != NULL)
    {
        printf("Joined String: %s\n", result);
        free(result); // Don't forget to free the allocated memory
    }
    else
    {
        printf("Memory allocation failure.\n");
    }

    return 0;
}
*/
