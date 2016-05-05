struct String *string_to_struct(char *str);

struct String
{
  char *str;
  int length;
};

/* used to debug string_to_struct function */
int main(void)
{
 char *str = "123456";
 string_to_struct(str);
 return (0);
 } 
