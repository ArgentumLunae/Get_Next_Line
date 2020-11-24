/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   noleak_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 13:04:05 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/23 13:10:30 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	printf("This program has no allocation, thus not leaks!");
	return (0);
}
