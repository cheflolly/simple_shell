#include "main.h"

/**
 * execute - a function that executes the given path
 *	     and the respective commands.
 * Return: Void
 */
void func(pid_t pid, pid_t id)
{
	char *path = "/bin/ls";
	char *argv[] = {path, "-l", "/tmp", NULL};
	if (pid == -1)
	{
		perror("Error while creating the child process");
	}
	if (pid == 0)
	{
		printf("I am child process and my ID is: %d\n", id);
		if (execve(path, argv, NULL) == -1)
		{
			perror("Error in executing");
		}
	}
	else
		wait(NULL);
		printf("I am the father and my ID is: %d\n", id);
}

/**
 * main - fork + wait + execve exercise
 * 
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid, id;

	pid = fork();
	id = getpid();
	func(pid, id);

	pid = fork();
	id = getpid();
	func(pid, id);

	pid = fork();
	id = getpid();
	func(pid, id);

	pid = fork();
	id = getpid();
	func(pid, id);

	pid = fork();
	id = getpid();
	func(pid, id);

	return (0);
}
