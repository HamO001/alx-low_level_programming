#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with the specified code.
 * @code: The exit code.
 * @msg: The error message to print.
 */
void error_exit(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * copy_file - Copies the content of one file to another file.
 * @src_file: The source file to read from.
 * @dest_file: The destination file to write to.
 */
void copy_file(const char *src_file, const char *dest_file)
{
	int fd_src, fd_dest, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	fd_src = open(src_file, O_RDONLY);
	if (fd_src == -1)
		error_exit(98, "Error: Can't read from file");

	fd_dest = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_dest == -1)
	{
		close(fd_src);
		error_exit(99, "Error: Can't write to file");
	}

	while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_dest, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_src);
			close(fd_dest);
			error_exit(99, "Error: Can't write to file");
		}
	}

	if (bytes_read == -1)
	{
		close(fd_src);
		close(fd_dest);
		error_exit(98, "Error: Can't read from file");
	}

	if (close(fd_src) == -1)
		error_exit(100, "Error: Can't close source file descriptor");

	if (close(fd_dest) == -1)
		error_exit(100, "Error: Can't close destination file descriptor");
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	copy_file(argv[1], argv[2]);

	return (0);
}
