*This project has been created as part of the 42 curriculum by tabading.*

# Table of Contents
- [Description](#description)

- [Instructions](#instructions)

- [Resources](#resources)

# Description
	A function that reads a file descriptor line by line, developed as part of the 42 curriculum.

| Item | Description |
|------|-------------|
| Function Name | `get_next_line` |
| Prototype | `char *get_next_line(int fd);` |
| Files to Submit | `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h` (all at the root of the repository) |
| Parameter | `fd`: The file descriptor to read from |
| Return Value | Read line: correct behavior<br>`NULL`: there is nothing else to read, or an error occurred |
| External Functions | `read`, `malloc`, `free` |
| Description | Write a function that returns a line read from a file descriptor |

# Instructions

	• Repeated calls (e.g., using a loop) to your get_next_line() function should let
		you read the text file pointed to by the file descriptor, one line at a time.
	• Your function should return the line that was read.
		If there is nothing left to read or if an error occurs, it should return NULL.
	• Make sure that your function works as expected both when reading a file and when
		reading from the standard input.
	• Please note that the returned line should include the terminating \n character,
		except when the end of the file is reached and the file does not end with a \n
		character.
	• Your header file get_next_line.h must at least contain the prototype of the
		get_next_line() function.
	• Add all the helper functions you need in the get_next_line_utils.c file.
	• Because you will have to read files in get_next_line(), add this option to your
		compiler call: -D BUFFER_SIZE=n
		It will define the buffer size for read().
		The buffer size value will be adjusted by your peer evaluators and the Moulinette
		to test your code.
	• You will compile your code as follows (a buffer size of 42 is used as an example):
		cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
		(Note: the files must be at the root of the repository).
	• get_next_line() exhibits undefined behavior if the file associated with the file
		descriptor is modified after the last call, while read() has not yet reached the end
		of the file.
	• get_next_line() also exhibits undefined behavior when reading a binary file. How-
		ever, you can implement a logical way to handle this behavior if you want to.

## Compilation
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=4(size) <files>.c

## Bonus
	• Develop get_next_line() using only one static variable.
	• Your get_next_line() can manage multiple file descriptors at the same time.
		For example, if you are reading from file descriptors 3, 4, and 5, you should be able
		to read from a different file descriptor with each call, without losing track of the
		reading state of each file descriptor or returning a line from a different one.
		This means you should be able to call get_next_line() to read from fd 3, then fd
		4, then fd 5, then again from fd 3, then fd 4, and so forth, without losing track of
		the reading state for each file descriptor

# Resources
- manual
- https://www.w3schools.com/c/
