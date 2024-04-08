/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:28:22 by rbarbier          #+#    #+#             */
/*   Updated: 2024/04/08 17:02:53 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while(argv[++j])
	{
		while(argv[j][i])
		{
			std::cout << (char)toupper(argv[j][i]);
			i++;
		}
		i = 0;
	}
	std::cout << std::endl;
}
