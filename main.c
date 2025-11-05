/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:29:33 by azirari           #+#    #+#             */
/*   Updated: 2025/11/05 19:22:51 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{   char buffer[5];
    
    int fd = open("test.txt", O_RDONLY);
    ssize_t test = read(fd, buffer, sizeof(buffer));
    printf("%ld", test);
    printf("\n%s\n", buffer);
}