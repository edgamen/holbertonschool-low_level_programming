#include <stdio.h>
void print_stars(int stars);
void print_spaces(int spaces);
void print_triangles (int h);

void triangles_in_the_term(int h, int n)
{
  if (n > 0 && h > 0)
    {
      for (; n > 0; n--)
	{
	  print_triangles(h);
	}
    }
}
 
void print_triangles(int h)
{
 int row, stars, spaces;

 for (row = 1; row <= h; row++)
   {
     spaces = h - row;
     stars = 2 * row - 1;
     print_spaces(spaces);
     print_stars(stars);
     printf("%c", '\n');
   }
 }
 
void print_stars(int stars)
{
  for (; stars > 0; stars --)
    {
      printf("%c", '*');
    }
}

void print_spaces(int spaces)
{
  for (; spaces > 0; spaces --)
  {
    printf("%c", ' ');
  }
}
