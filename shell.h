#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
ssize_t _input(char *buffer, size_t _size);
int simple(int n1, int n2);
void freedom(char **args);
void execute(char *str, char *argv[]);
int main(int argc, char *argv[]);
ssize_t _getline(char *buffer, size_t buf_size);
int tfer_input(char *input, char *args[]);
#endif
