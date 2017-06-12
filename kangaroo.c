//A program for kangaroo puzzle
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const * argv[])
{
  int x1 = atoi(argv[1]) , v1 = atoi(argv[2]) , x2 = atoi(argv[3]), v2 = atoi(argv[4]);
  if(v2 >= v1)
  {
    printf("NO");
  }
  else
  {
    if((x2-x1)%(v1-v2) == 0)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}
