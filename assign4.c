#include <stdio.h>
#include <stdlib.h>

int palindromelength (char *str, int i, int j) {
  while (i < j) {
    if (str[i] != str[j])
      return (-1);
    i++;
    j--;
  }
  return (j-i+1);
}

  int main () {

  char data[100];
  char *str;
  int n, i, j, first, last, maxlength = 0;

  printf("Enter a string\n");
  gets(data);

  str = data;
  n = strlen(data);


  for (i = 0; i < n; i++) {
    for (j = i+1; j < n; j++) {
      int result = palindromelength(str, i, j);
      if (result != -1) {
	if (maxlength < result) {
	  maxlength = result;
	  first = i;
	  last = j;
	}
      }
    }
  }

  printf("Largest palindrome is: ");
  for (i = first; i <= last; i++)
    printf("%c", str[i]);
  printf("\n");
  
  return (0);
  }
