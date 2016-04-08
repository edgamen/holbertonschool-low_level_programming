void print_char(int n);
void print_number(int n);
int get_digits(int n);
int get_power (int digits);

/* print each element of an array of integers */
void print_array(int *a, int n)
{
  int i;
  
  for (i = 0; i < n - 1; i++)
    {
      print_number(a[i]);
      print_char(',');
      print_char(' ');
    }

  print_number(a[n - 1]); /* print the last element */
  print_char('\n');
}

/* print an integer digit-by-digit */
void print_number(int num)
{
  int digit;
  int digits = get_digits(num); 
  int power = get_power(digits);
  
  for (; digits > 0; digits--)
    {
      digit = num / power;
      print_char(digit + '0');
      num = num % power;
      power = power / 10;
    }
}

/* get the number of digits in a given number */
int get_digits(int num)
{
  int digits;
  
  for (digits = 0; num > 0; num = num / 10)
  {
    digits++;
  }

  return (digits);
}

/* return the power of a number */
int get_power(int digits)
{
  int power;
  
  for (power = 1; digits > 1; digits--)
    {
      power = power * 10;
    }
  
  return (power);
}
