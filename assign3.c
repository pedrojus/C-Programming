#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Coded by Pedro Jusino

//Computes the factorial of n
int factorial (int n) {
  int result = 1;
  int i;
  for (i = 1; i <= n; i++)
    result *= i;

  return result;
}

//Computes the sum of the first n terms of e to the x using approximation
double exponent (double x, int n) {
  double sum = 0;
  int i; 

  for (i = 0; i <= n; i++)
    sum += pow(x,i)/factorial(i);

  return sum;
}

int main (int argc, char* argv[]) {

  int n = atoi(argv[1]);
  double x = atof(argv[2]);
  int i;

  //Prints the header for the table
  printf("\ti\t\tApproximation\n");
  printf("--------------------------------------------\n");

  for(i = 0; i <= n; i++)
    printf("\t%4d\t\t%.10f\n", i, exponent(x, i));

  printf("Exact value = %.10f\n", exp(x));
}
