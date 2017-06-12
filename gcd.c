//A program to find gcd of two numbers
#include<stdio.h>
int lcm(int a, int b);

void main(int argc, char const *argv[])
{
  int a, b;
  printf("Enter the number for which you want to find Gcd and Lcm\n");
  scanf("%d %d", &a, &b);
  printf("LCM of giver number : %d \n", lcm(a,b));
}


int lcm(int a, int b)
{
  int number1 = a;
  int number2 = b;
  while (a != b)
  {
    if(a>b)
    {
      a = a-b;
    }
    else
    {
      b = b-a;
    }
  }
  return (number1*number2)/a;
}
