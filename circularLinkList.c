//A program circular link list ADT
#include<stdio.h>
#include<stdlib.h>

int linkListSize();
void enterNodeAtBegining();
void traverse();
void enterNodeAtEnd();
void enterAtAPosition();

struct listNode
{
  int data;
  struct listNode *node;
}*start;

void main(int argc, char const *argv[])
{
  int loopFlag = 1;
  int choice;
  start = NULL;
  printf("A singly link list program\n");
  while (loopFlag)
  {
    printf("\n\n\n");
    printf("Current size of Link List : %d\n", linkListSize());
    printf("***************circular Link list*********************\n");
    printf("***************Please Enter your choice*************** \n");
    printf("1. Enter node at the begining\n");
    printf("2. Enter node at the end\n");
    printf("3. Enter node at a position\n");
    printf("4. Traverse Link list\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1  : enterNodeAtBegining();
                break;
      case 2  : enterNodeAtEnd();
                break;
      case 3  : enterAtAPosition();
                break;
      case 4  : traverse();
                break;
      case 5 : loopFlag = 0;
                break;
    }
  }
}


//For the size of link list
int linkListSize()
{
  int count = 0;
  if(start==NULL)
  {
    return count;
  }
  else
  {
    struct listNode *ptr = start;
    count = 0;
    do
    {
      count++;
      ptr = ptr->node;
    } while(ptr != start);
    return count;
  }
}


//For entering node at begining
void enterNodeAtBegining()
{
  int n;
  struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
  struct listNode *ptr = start;
  if(newNode)
  {
    printf("Enter the number you want to enter into node\n");
    scanf("%d", &(newNode->data));
    if(start == NULL)
    {
      start = newNode;
      newNode->node = start;
    }
    else
    {
      while(ptr->node != start)
      {
        ptr = ptr->node;
      }
      newNode->node = start;
      start = newNode;
      ptr->node = start;
    }
  }
  else
  {
    printf("Running out of memory\n");
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

void enterAtAPosition()
{
  struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
  int position;
  int i = 1;
  struct listNode *ptr1 = start;
  struct listNode *ptr2;
  if(newNode)
  {
    printf("Please enter the position in which you want to enter \n");
    scanf("%d", &position);
    printf("Please enter the data\n");
    scanf("%d", &(newNode->data));
    if(position == 1)
    {
      if(start == NULL)
      {
        start = newNode;
        newNode->node = start;
        return;
      }
      else
      {
        while(ptr1->node != start)
          ptr1 = ptr1->node;
        newNode->node = start;
        start = newNode;
        ptr1->node = start;
        return;
      }
    }
    else
    {
      do
      {
        ptr2 = ptr1;
        ptr1 = ptr1->node;
        i++;
      } while(ptr1 != start && i<position);
      if(i==position)
      {
        printf("hello\n");
        ptr2->node = newNode;
        newNode->node = ptr1;
      }
      else
      {
        printf("Sorry this position doesn't exists\n %d", i);
      }
    }
  }
  else
  {
    printf("Sorry, Running out of memory\n");
  }
}
