#include<stdio.h>
#include<malloc.h>

//A simple to do some tasks on link list like find modular node, division node and root node on basis of some number given.
struct listNode
{
  int data;
  struct listNode *node;
};

void enterNodeAtBegining(struct listNode **start, int value);
void traverse(struct listNode *start);
struct listNode * moudularNodeFromEnd(struct listNode  *start, int number);
struct listNode * divisionNodeFromStart(struct listNode *start, int number);
struct listNode * rootNthNode(struct listNode *start);


void main(int argc, char const *argv[])
{
  int numberOfNodes;
  int number;
  printf("Enter the Number you want to enter in Linklist\n");
  scanf("%d", &numberOfNodes);
  struct listNode *start = NULL;
  struct listNode *tempNode = NULL;
  while (numberOfNodes--)
  {
    printf("Enter the data you want to enter \n");
    scanf("%d", &number);
    enterNodeAtBegining(&start, number);
  }
  printf("Data successfully enter in Link list. Data is as follows-->\n");
  traverse(start);
  printf("Enter the constant for which you want to find modular from end in link list\n");
  scanf("%d", &number);
  tempNode = moudularNodeFromEnd(start, number);
  printf("The node at modular position from end is --> %d\n", tempNode->data);
  printf("Enter the constant for which you want to find division from start in link list\n");
  scanf("%d", &number);
  tempNode = divisionNodeFromStart(start, number);
  printf("The node at division node from start is --> %d\n", tempNode->data);
  tempNode = rootNthNode(start);
  printf("The node at root nth node from start is --> %d\n", tempNode->data);
}



//For entering node at begining
void enterNodeAtBegining(struct listNode **start, int value)
{
  struct listNode *ptr = (struct listNode *)malloc(sizeof(struct listNode));
  if(ptr)
  {
    ptr->data = value;
    ptr->node = NULL;
    if(*start == NULL)
    {
      *start = ptr;
    }
    else
    {
      ptr->node = *start;
      *start = ptr;
    }
  }
  else
  {
    printf("Running out of memory\n");
  }

}


//For traversing link list
void traverse(struct listNode *start)
{
  struct listNode *ptr = start;
  if(start == NULL)
  {
    printf("No element present\n");
  }
  else
  {
    while (ptr != NULL)
    {
      printf("%d", ptr->data);
      if(ptr->node != NULL)
      {
        printf(" -> ");
      }
      ptr = ptr->node;
    }
    printf("\n");
  }
}

struct listNode * moudularNodeFromEnd(struct listNode *start, int number)
{
  struct listNode *ptr1 = start;
  struct listNode *ptr2 = start;
  number = number;
  while (number--)
  {
    ptr1 = ptr1->node;
  }
  while (ptr1)
  {
    ptr1 = ptr1->node;
    ptr2 = ptr2->node;
  }
  return ptr2;
}

struct listNode * divisionNodeFromStart(struct listNode *start, int number)
{
  struct listNode *tempNode = NULL;
  struct listNode *ptr = start;
  int i = 1;
  while(ptr)
  {
    if(i%number == 0)
    {
      if(tempNode == NULL)
        tempNode = start;
      else
        tempNode = tempNode->node;
    }
    ptr = ptr->node;
    i++;
  }
  if(tempNode == NULL)
  {
    tempNode = start;
  }
  return tempNode;
}

struct listNode * rootNthNode(struct listNode *start)
{
  struct listNode *ptr = start;
  struct listNode *resultingNode = NULL;
  int i=1, sqrt=1;
  while (ptr)
  {
    if(i == sqrt*sqrt)
    {
      if(resultingNode == NULL)
        resultingNode = start;
      else
        resultingNode = resultingNode->node;
      sqrt++;
    }
    ptr = ptr->node;
    i++;
    printf("value of i : %d\n", i);
  }
  return resultingNode;
}
