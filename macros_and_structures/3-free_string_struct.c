#include <stdlib.h>
#include "str_struct.h"

/* frees a String struct allocated by malloc */
void free_string_struct(struct String *str)
{
  free(str->str);
  free(str);
}
