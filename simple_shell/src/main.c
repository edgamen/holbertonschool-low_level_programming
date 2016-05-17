#Ainclude "shell_functions.h"
#include "libshell.h"
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#define PROMPT "prompt"
#define PATH_VAR find_path_var(env)

/* A simple UNIX command interpreter (shell) */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char *input;
	char **exec_argv;
	char *found_path;
	int status;
	int return_value;

	status = 0;
	return_value = 0;

	while (1) {

		print_prompt(PROMPT);
		input = read_line(0);

		/* if there was some error allocating the string */
		if (input == NULL) {
			print_string("Failed to read input. Exiting shell.\n");
			return (1);
		}
		exec_argv = string_split(input, ' ');

		/* if there was some error allocating the array */
		if (exec_argv == NULL) {
			print_string("Ran out of memory. Exiting shell.\n");
			free(input);
			return (2);
		}

		/* if empty input is provided by pressing enter */
		if (exec_argv[0] == NULL) {
			goto end_of_loop;
		}

		/* detect built-in functions */
		if (string_compare(exec_argv[0], "exit")) {
			set_return(&return_value, exec_argv[1]);
			goto clear_memory_exit;
		} else if (string_compare(exec_argv[0], "env")) {
			print_array(env);
		} else if (string_compare(exec_argv[0], "$?")) {
			print_number(status);
			print_char('\n');
		} else {
			found_path = find_exec_path(PATH_VAR, exec_argv[0]);
			if (found_path != NULL) {
				free(exec_argv[0]);
				exec_argv[0] = found_path;
			}
			status = call_child(exec_argv, env);
			/* means exec could not find the program provided
			   and returned to the child process */
			if (status < -1) {
				return_value = -2;
				goto clear_memory_exit;
			}
		}

	end_of_loop:
		free(input);
		free_str_array(exec_argv);
	}

	return 0;

clear_memory_exit:
	free(input);
	free_str_array(exec_argv);
	return return_value;
}

/* Function: sets the return value of the program */
void set_return(int *ret_value, char *s)
{
	int i;

	if (s == NULL) {
		*ret_value = 0;
		return;
	}
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] < '0' || s[i] > '9') {
			*ret_value = 0;
			return;
		}
	}

	*ret_value = string_to_integer(s);
}

/* Function: tries to find the path that
   contains the requested executable */
char *find_exec_path(char *path_var, __attribute__((unused)) char *exe)
{
	char **paths;
	char *dirname;
	char *temp;
	DIR *dir;
	int i;

	if (path_var == NULL) {
		print_string("Error: could not find $PATH var");
		return NULL;
	}

	paths = string_split(path_var, ':');
	if (paths == NULL) {
		print_string ("Error: ran out of memory to allocate an array.");
		return NULL;
	}

	for (i = 0; paths[i] != NULL; i++)
	{
		dirname = paths[i];
		dir = opendir(dirname);
		if (dir == NULL) {
			perror("opendir");
			/* not sure yet if I want to return
			   instead of continue through loop:
			   free_str_array(paths);
			   return NULL; */
		}
		if (search_dir(dir, exe) == 1) {
			/* add clauses to deal if malloc fails: */
			temp = string_concat(paths[i], "/");
			dirname = string_concat(temp, exe);
			free(temp);
			free_str_array(paths);
			if (closedir(dir) == -1) {
				perror("closedir");
			}
			return dirname;
		}
		if (closedir(dir) == -1) {
			perror("closedir");
		}
	}

	free_str_array(paths);

	return NULL;
}

int search_dir(DIR *dir, char *exe)
{
	struct dirent *dirstruct;

	while (1) {
		dirstruct = readdir(dir);
		if (dirstruct == NULL) {
			/* consider checking errno to determine if error
			   or end of the readable directories */
			break;
		}
		if (string_compare(dirstruct->d_name, exe) == 1) {
			return 1;
		}

	}

	return 0;
}

/* Function: return element in the env
   array that corresponds to $PATH */
char *find_path_var(char **env)
{
	int i;
	char *var;

	for (i = 0; env[i] != NULL; i++) {
		var = env[i];
		if (var[0] == 'P' && var[1] == 'A' &&
			var[2] == 'T' && var[3] == 'H'
			&& var[4] == '=') {
			/* return the PATH string from after the = */
			return (var + 5);
		}
	}

	return NULL;
}

/* Function: execute a program passed as an argument
   in a child process */
int call_child(char **exec_argv, char **env)
{
	pid_t pid;
	int status;

	if ((pid = fork()) == -1) {
		perror("fork");
		return (-1);
	}
	if (pid == 0) {
		execve(exec_argv[0], exec_argv, env);
		perror(exec_argv[0]);
		return (-2);
	} else {
		wait(&status);
	}

	return status;
}

/* Function: print a prompt */
void print_prompt(char *s)
{
	print_string(s);
	print_char('$');
	print_char(' ');
}

/* Function: free an allocated arrray of allocated strings */
void free_str_array(char **str_array)
{
	int i;

	for (i = 0; str_array[i] != NULL; i++) {
		free(str_array[i]);
	}

	free(str_array);
}
B
