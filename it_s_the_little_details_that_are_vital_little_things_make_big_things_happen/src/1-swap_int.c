/* swaps the values of two integers */
void swap_int(int *a, int *b)
{
  int avalue = *a;
  int bvalue = *b;
  *a = bvalue;
  *b = avalue;
}
