int print_char(char c);

/* function that draws a straight line on the terminal */
void print_line(int n)
{
  
  for (; n > 0; n--)
    {
      print_char('_');
    }
  
    print_char('\n');
 
}
