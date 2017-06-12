#include<stdio.h>
#include<malloc.h>
void enterNodeAtEnd();
void traverse();

struct listNode
{
  int data;
  struct listNode *node;
}*start;

struct listNode * eliminationGame(struct listNode *, int, int);

int main(int argc, char const *argv[])
{
  int count;
  int eliminationPoint;
  start = NULL;
  printf("Enter the Number of nodes you want to have in the link list\n");
  scanf("%d", &count);
  int tempCount = count;
  while (count--)
  {
    enterNodeAtEnd();
  }
  printf("All the data successfully entered, the list is as follows\n");
  traverse();
  printf("Enter the elimination point for each time\n");
  scanf("%d", &eliminationPoint);
  struct listNode *finalNode = eliminationGame(start, eliminationPoint, tempCount);
  printf("%d\n", finalNode->data);
  return 0;
}


//For entering data at the end
void enterNodeAtEnd()
{
  struct listNode *ptr = start;
  struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
  if(newNode)
  {
    printf("Enter the data\n");
    scanf("%d", &(newNode->data));
    if(start == NULL)
    {
      start = newNode;
      newNode->node = start;
      return;
    }
    while (ptr->node != start)
    {
      ptr = ptr->node;
    }
    newNode->node = start;
    ptr->node = newNode;
  }
  else
  {
    printf("Sorry, running out of memory\n");
  }
}

//For traversing link list
void traverse()
{
  struct listNode *ptr = start;
  if(start == NULL)
  {
    printf("No element present\n");
  }
  else
  {
    do
    {
      printf("%d", ptr->data);
      if(ptr->node != start)
      {
        printf(" -> ");
      }
      ptr = ptr->node;
    } while(ptr != start);
    printf("\n");
  }
}

struct listNode * eliminationGame(struct listNode *tempNode, int eliminationPoint, int sizeOfList)
{
  int count = sizeOfList - 1;
  int tempEliminationPoint = eliminationPoint-1;
  printf("%d %d\n", eliminationPoint-1, sizeOfList);
  while (count--)
  {
    for(int i = 0; i<eliminationPoint-1; i++)
    {
      tempNode = tempNode->node;
    }
    tempNode->node = tempNode->node->node;
  }
  return tempNode;
}
