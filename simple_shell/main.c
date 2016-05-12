#include "shell_functions.h"
#include "libshell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define PROMPT "prompt"
#include <stdio.h>

/* A simple UNIX command interpreter (shell) */
/* this will be longer than the previous version but maybe simpler */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, __attribute__((unused))char **env)
{
  char *input;
  char **exec_argv;
  int status;

  while (1) { 

    print_prompt(PROMPT);
    input = read_line(0); 

    /*if (input[0] == NULL)
      {
	printf("input is null");
	} */ /*look into this later */
    
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
    if (exec_argv[0] == NULL)
      {
	free(input);
	free_str_array(exec_argv);
	continue;
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
    }
    else { 
      /* is there a way to store the value in status 
	 in the env var "$?"? */
      status = call_child(exec_argv, env);
      
      /* means exec could not find the program provided
	 and returned to the child process */
      if (status < -1) {
	free(input);
	free_str_array(exec_argv);
	return (-2);
	} 
    }
    
    free(input);
    free_str_array(exec_argv);
   
      /* END WHILE LOOP */
  }
  
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
    perror(exec_argv[0]);
    return (-2);
  }
  else {
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
