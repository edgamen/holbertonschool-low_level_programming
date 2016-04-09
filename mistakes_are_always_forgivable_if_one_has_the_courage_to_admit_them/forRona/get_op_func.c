/*int (*pointer_to_NULL)(int, int) = &return_NULL;*/

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);


/* get_op_func takes the parameter char c and finds the appropriate pointer to one of the op functions */

int (*get_op_func(char c))(int, int)
{
  int i;
  char symbol[5] = {'+', '-', '*', '/', '%'};
  int (*op_func[5]) (int a, int b);
  
  op_func[0] = op_add;
  op_func[1] = op_sub;
  op_func[2] = op_mul;
  op_func[3] = op_div;
  op_func[4] = op_mod;
  
  for (i = 0; i < 5; i++)
    {
      if (c == symbol[i])
	{
	  return op_func[i];
	}
    }

  return 0;
}
