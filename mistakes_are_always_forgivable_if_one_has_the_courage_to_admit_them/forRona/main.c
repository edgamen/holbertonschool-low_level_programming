#include <stdio.h>
#include <stdlib.h>

int (*get_op_func(char c))(int, int);

int main (int ac, char **av) {
  ac++;
  /* av[1] is the first operand, in string form */
  /* av[2] is the operator, in char form */
  /* av[3] is the second operand, in string form */

  /* let's define the variables we need */
  int first_operand = atoi(av[1]);
  char * operator_string = av[2];
  char operator = operator_string[0];
  int second_operand = atoi(av[3]);

  int (*func_to_call)(int, int); /* func_to_call is var to hold the pointer we want to use */
  
  func_to_call = get_op_func(operator); /* we use get_op_func to assign the appropriate pointer to our var */
  printf("%d\n", func_to_call(first_operand, second_operand)); /* now we use func_to_call (our pointer) to call our op function */
  return 0;
}

    /*
int return_NULL(void) {
  return ;
}
    */
