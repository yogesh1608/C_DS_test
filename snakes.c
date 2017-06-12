//A codechef problem for snakes race
#include<stdio.h>
#include<malloc.h>

int main(int argc, char const *argv[])
{
  int noOfReports;
  char *string;
  char *finalOutput;
  int state;
  int i, j;
  int noOfCharactersInString = 0;
  scanf("%d\n", &noOfReports);
  finalOutput = (char *)malloc(noOfReports * sizeof(char));
  for(i = 0; i<noOfReports; i++)
  {
    scanf("%d", &noOfCharactersInString);
    string = (char *)malloc(sizeof(char) * noOfCharactersInString);
    scanf("%s", string);
    state = 0;
    for (j = 0; j<noOfCharactersInString; j++)
    {
      if(string[j] == 'H' && state == 0)
        state = 1;
      else if(string[j] == 'T' && state == 0)
      {
        state = 2;
        break;
      }
      else if(string[j] == 'T' && state == 1)
        state = 0;
      else if(string[j] == 'H' && state == 1)
      {
        state = 2;
        break;
      }
      else if(string[j] != '.')
      {
        state = 2;
        break;
      }
    }
    if(state == 0)
      finalOutput[i] = '1';
    else if(state == 1 || state == 2)
      finalOutput[i] = '0';
  }
  for(i = 0; i<noOfReports; i++)
  {
    if(finalOutput[i] == '1')
      printf("Valid\n");
    else
      printf("Invalid\n");
  }
  return 0;
}
