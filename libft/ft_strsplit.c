/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:41:54 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 20:54:11 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_count_letters(char *str, char c)
{
	int a;

	a = 0;
	while (str[a] != c && str[a])
		a++;
	return (a);
}

static	char	*ft_return_word(char *str, char c)
{
	int		a;
	char	*word;

	if (!(word = malloc(ft_count_letters(str, c) + 1)))
		return (NULL);
	a = 0;
	while (str[a] != c && str[a])
	{
		word[a] = str[a];
		a++;
	}
	word[a] = '\0';
	return (word);
}

static	int		ft_count_words(const char *str, char c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (str[0] != c && str[0])
		b++;
	while (str[a])
	{
		if (str[a] == c && str[a + 1] != c && str[a + 1])
			b++;
		a++;
	}
	return (b);
}

static char		**ft_scd(char const *str, char c, int f, char **tab)
{
	int a;
	int b;
	int i;

	a = 0;
	b = 0;
	i = 0;
	while (f--)
	{
		while (str[a] == c)
			a++;
		if (!(tab[b++] = ft_return_word((char *)&str[a], c)))
		{
			free(tab);
			return (NULL);
		}
		a += ft_count_letters((char *)&str[a], c);
		i = 0;
	}
	tab[b] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	int		a;
	int		b;
	int		i;
	int		f;
	char	**tab;

	a = 0;
	b = 0;
	i = 0;
	if (!str)
		return (NULL);
	f = ft_count_words(str, c);
	if (!(tab = (char **)malloc(sizeof(char *) * f + 1)))
		return (NULL);
	return (ft_scd(str, c, f, tab));
}
