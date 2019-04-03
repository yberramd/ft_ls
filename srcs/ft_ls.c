/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/03 16:00:21 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int add_args(int args, const char *argv)
{
	int a;

	a = 0;
	while (argv[++a])
	{
		a += argv[a] & ARG_R;
	}
	return (args);
}

int ls(int attr, const char *path)
{
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int args;

	args = 0;
	if (argc <= 1)
		return (ls(args, argv[0]));
	while (++i < argc)
		if (argv[i][0] == '-')
			add_args
}
