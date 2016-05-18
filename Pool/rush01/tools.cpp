/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:22:33 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/17 16:22:43 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

#include "tools.hpp"

void command_output(char *buf, const size_t size, const char *path,
					char *const argv[])
{
	int fd[2];
	pid_t pid;

	bzero(buf, size);
	if (pipe(fd) == -1)
		return;

	if ((pid = fork()) == -1)
		return;

	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execv(path, argv);
		_exit(1);
	}
	else {
		close(fd[1]);
		read(fd[0], buf, size);
		char *ptr = strrchr(buf, '\n');
		if (ptr) *ptr = '\0';
		wait(0);
	}
}
