#include<stdio.h>
//A program for tower of hanoi

void towerOfHannoi(int n, char a, char b, char c);

void main(int argc, char const *argv[])
{
  int n;
  printf("Tower of Hannoi Game: \n");
  printf("Enter the number of rings you want to play with :\n");
  scanf("%d", &n);
  towerOfHannoi(n , 'A', 'B', 'C');
}

void towerOfHannoi(int n, char a, char b, char c)
{
  if(n==1)
  {
    printf("Move ring from %c -> %c \n", a, c);
  }
  else
  {
    towerOfHannoi(n-1, a, c, b);
    printf("Move ring from %c -> %c \n", a, c);
    towerOfHannoi(n-1, b, a, c);
  }
}
