#include <dirent.h>
int print_char(char c);
void print_string(char *str);
void print_prompt(char *s);
void print_array(char **array);
int string_compare(char *s1, char *s2);
char *string_concat(char *s1, char *s2);
int string_to_integer(char *s);
void free_str_array(char **str_array);
int call_child(char **exec_argv, char **env);
void set_return(int *ret_value, char *s);
char *find_path_var(char **env);
char *find_exec_path(char *path_var, __attribute__((unused)) char *exe);
int search_dir(DIR *dir, char *exe);

/* int parse_input(char *input, char **exec_argv, char **env, int status); */
