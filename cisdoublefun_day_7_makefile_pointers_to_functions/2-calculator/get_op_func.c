#define NULL 0

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/* retrieve the correct function based on the operator symbol */
int (*get_op_func(char c))(int, int)
{
  int (*array_of_functions[5]) (int a, int b);
  char operator[5] = {'+', '-', '*', '/', '%'};
  int i;

  i = 0;
  array_of_functions[0] = &op_add;
  array_of_functions[1] = &op_sub;
  array_of_functions[2] = &op_mul;
  array_of_functions[3] = &op_div;
  array_of_functions[4] = &op_mod;

  while (i < 5)
    {
      if (operator[i] == c)
	{
	  return array_of_functions[i];
	}
      i++;
    }

  return NULL;
}
