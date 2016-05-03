#include <stdlib.h>

char *extract_word(char *s);
int find_word_length(char *s);
char **create_array(int n);
int find_number_words(char *s);
void advance_position(char *s, int *position);
void free_memory(char** array_of_strings, int n);

/* turns a string into an array of words */
char **string_to_words(char *s)
{
  int position_of_next_word;
  char **array_of_strings;
  int words;
  int i;

  i = 0;
  words = find_number_words(s);
  array_of_strings = create_array(words);

  if (array_of_strings == NULL)    
    {
      return NULL;
    }
 
  while (i < words)
    {
      array_of_strings[i] = extract_word(s);
      
      if (array_of_strings[i] == NULL)
	{
	  free_memory(array_of_strings, i);
	  return NULL;
	}
      
      advance_position(s, &position_of_next_word);
      
      /* advance through string to continue extracting new words */
      s = (s + position_of_next_word);
      
      i++;
    } 
  
  return array_of_strings;	 
}

void free_memory(char** array_of_strings, int n)
{
  int i;

  i = 0;
  while (i < n)
    {
      free(array_of_strings[i]);
      i++;
    }
   free(array_of_strings);
}

/* find the number of words to store in an array */
int find_number_words(char *s)
{
  int i;
  int words;

  i = 0;
  words = 0;

  while (s[i] != '\0')
    {
      if ( !(s[i] >= 'a' && s[i] <= 'z') &&
	   !(s[i] >= 'A' && s[i] <= 'Z') &&
	   !(s[i] >= '0' && s[i] <= '9') &&
	   ((s[i + 1] >= 'a' && s[i + 1] <= 'z') ||
	    (s[i + 1] >= 'A' && s[i + 1] <= 'Z') ||
	    (s[i + 1] >= '0' && s[i + 1] <= '9'))
	 )
	{
	  words++;
	}
      i++;
    }

  /* account for last word in sentence */
  words++;
  
  return words;
}

/* create an array to store words of a string */
char **create_array(int words)
{
  char **array_of_strings;
  
  array_of_strings = malloc((words + 1) * sizeof(char *));

  /* if malloc fails: */
  if (array_of_strings == NULL)
    {
      return (NULL);
    }

  /* make the last item of the array a NULL pointer */
  array_of_strings[words] = NULL;

  return array_of_strings;
  
}

/* advance position until the next word */
void advance_position(char *s, int *position)
{
  int i;
  *position = find_word_length(s);

  i = *position;
  while ( !(s[i] >= 'a' && s[i] <= 'z') &&
	  !(s[i] >= 'A' && s[i] <= 'Z') &&
	  !(s[i] >= '0' && s[i] <= '9'))
    {
      i ++;
      *position = *position + 1;
    }
}

/* find the length of the first word in a string */
int find_word_length(char *s)
{
  int i;

  i = 0;
  while ( (s[i] >= 'a' && s[i] <= 'z') ||
	  (s[i] >= 'A' && s[i] <= 'Z') ||
	  (s[i] >= '0' && s[i] <= '9') )
    {
      i++;
    }

  return i;
}

/* extract the first word in a string */
char *extract_word(char *s)
{
  int i;
  char *word;

  word = malloc(find_word_length(s) * sizeof(char));

  /* if malloc fails */
  if (word == NULL)
    {
      return NULL;
    }

  i = 0;
  while ( (s[i] >= 'a' && s[i] <= 'z') ||
	  (s[i] >= 'A' && s[i] <= 'Z') ||
	  (s[i] >= '0' && s[i] <= '9') )
    {
      word[i] = s[i];
      i++;
    }

  /* append null character */
  word[i] = '\0';

  return word;
}
