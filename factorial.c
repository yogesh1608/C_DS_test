#include<stdio.h>
int factorial(int n);
//Code to find factorial recursively
void main()
{
    int n;
    printf("Enter the number for which you want to find the factorial\n");
    scanf("%d", &n);
    printf("The factorial of number is : %d\n", factorial(n));
}

int factorial(int n)
{
  if(n==0 || n==1)
  {
    return 1;
  }
  else
  {
    return n*factorial(n-1);
  }
}
