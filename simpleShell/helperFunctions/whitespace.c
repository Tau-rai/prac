void lstrip(char *s)
{
  while (*s == ' ')
  {
    s++;
  }
}

void rstrip(char *s)
{
  char *end = s + _strlen(s) - 1;
  while (end >= s && *end == ' ')
  {
    end--;
  }
  *(end + 1) = '\0';
}
