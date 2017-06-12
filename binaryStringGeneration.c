#include<stdio.h>
#include<malloc.h>
//Generation of all the string of n-bit through back tracking.

void binary(char *arr, int n);

void main(int argc, char const *argv[])
{
  int n;
  char *arr;
  printf("A program to Generation all sting of n-bit \n");
  printf("Enter the number of bits for the string \n");
  scanf("%d", &n);
  arr = (char *)(malloc(n*sizeof(char)));
  if(arr)
  {
    binary(arr, n);
  }
  else
  {
    printf("Not Enough memory\n");
  }
}

void binary(char *arr, int n)
{
  if(n<1)
  {
    printf("%s\n", arr);
  }
  else
  {
    *(arr + n - 1) = '0';
    binary(arr, n-1);
    *(arr + n - 1) = '1';
    binary(arr, n-1);
  }
}
