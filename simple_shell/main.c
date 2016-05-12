#include "shell_functions.h"
#include "libshell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define PROMPT "prompt"
#include <stdio.h>

/* A simple UNIX command interpreter (shell) */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, __attribute__((unused))char **env)
{
  char *input;
  char **exec_argv;
  int status;
  
  print_prompt(PROMPT);
  input = read_line(0); /* read a line from stdin */

  /* if there was some error allocating the string */
  if (input == NULL) {
      /* hopefully the read_line function prints an 
	 appropriate error message */
      print_string("input: Exiting program.\n");
      return (1);
    }
  exec_argv = string_split(input, ' ');
  /* if there was some error allocating the array */
  if (exec_argv == NULL) {
      /* hopefully the string_split function prints an 
	 appropriate error message */
      print_string("exec_argv: Exiting program.\n");
      free(input);
      return (1);
    }
  
  /* detect built-in functions */
  if (string_compare(exec_argv[0], "exit")) {
      print_string("Need to exit.\n");
      free_str_array(exec_argv);
      free(input);
      return (0);
    }
  else if (string_compare(exec_argv[0], "env")) {
      print_string("Need to print env variables.\n");
      return (0);
    }
  else {
    status = call_child(exec_argv, env);
    printf("status of child: %d\n", status);
    /* is there a way to store the value in status 
       in the env var "$?"? */
  }

  
  /* debugging statements 
  printf("%s", exec_argv[0]);
  printf("%s", exec_argv[1]);*/

  /* at the end, we must free all malloc'd items */
  free_str_array(exec_argv);
  free(input);
  
  return (0);
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
  }

  wait(&status);
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
