#include<stdio.h>
#include<malloc.h>

//A program to for link list adt.
int linkListSize();
void enterNodeAtBegining();
void traverse();
void enterNodeAtEnd();
void enterAtAPosition();
void deleteNodeFromBegining();
void deleteNodeAtEnd();
void deleteAtAPosition();
void search();
void removeWholeLinkList();
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
    printf("***************Please Enter your choice*************** \n");
    printf("1. Enter node at the begining\n");
    printf("2. Enter node at the end\n");
    printf("3. Enter node at a position\n");
    printf("4. Traverse Link list\n");
    printf("5. Deleting node at begining\n");
    printf("6. Deleting node at end \n");
    printf("7. Deleting node at a position\n");
    printf("8. Search a node\n");
    printf("9. Remove Whole Link List\n");
    printf("10. Exit\n");
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
      case 5  : deleteNodeFromBegining();
                break;
      case 6  : deleteNodeAtEnd();
                break;
      case 7  : deleteAtAPosition();
                break;
      case 8  : search();
                break;
      case 9  : removeWholeLinkList();
                break;
      case 10 : loopFlag = 0;
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
    while(ptr != NULL)
    {
      count++;
      ptr = ptr->node;
    }
    return count;
  }
}


//For entering node at begining
void enterNodeAtBegining()
{
  int n;
  struct listNode *ptr = (struct listNode *)malloc(sizeof(struct listNode));
  if(ptr)
  {
    printf("Enter the number you want to enter into node\n");
    scanf("%d", &(ptr->data));
    ptr->node = NULL;
    if(start == NULL)
    {
      start = ptr;
    }
    else
    {
      ptr->node = start;
      start = ptr;
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


void enterNodeAtEnd()
{
  struct listNode *ptr = start;
  struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
  if(newNode)
  {
    printf("Enter the data you want to enter\n");
    scanf("%d", &(newNode->data));
    newNode->node = NULL;
    if(start == NULL)
    {
      start = newNode;
    }
    else
    {
      while(ptr->node != NULL)
      {
        ptr = ptr->node;
      }
      ptr->node = newNode;
    }
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
      newNode->node = start;
      start = newNode;
      return;
    }
    while(ptr1 != NULL && i<position)
    {
      ptr2 = ptr1;
      ptr1 = ptr1->node;
      i++;
    }
    if(i == position)
    {
      newNode->node = ptr1;
      ptr2->node = newNode;
    }
    else
    {
      printf("Sorry this position on present link list doesn't exist\n");
    }
  }
  else
  {
    printf("Sorry, Running out of memory\n");
  }
}


void deleteNodeFromBegining()
{
  struct listNode *ptr;
  if(start == NULL)
  {
    printf("No Node eixsts\n");
    return;
  }
  ptr = start;
  start = start->node;
  free(ptr);
  printf("Node successfully deleted\n");
}

void deleteNodeAtEnd()
{
  struct listNode *ptr;
  ptr = start;
  if(start == NULL)
  {
    printf("No Node exists\n");
    return;
  }
  if(start->node == NULL)
  {
    start = NULL;
    free(ptr);
    printf("Node successfully deleted\n");
    return;
  }
  while (ptr->node->node != NULL)
  {
    ptr = ptr->node;
  }
  free(ptr->node);
  ptr->node = NULL;
  printf("Node successfully deleted\n");
}

void deleteAtAPosition()
{
  struct listNode *ptr1;
  struct listNode *ptr2;
  int position;
  ptr1 = start;
  int i=1;
  printf("Please provide the position of that node\n");
  scanf("%d", &position);
  if(start == NULL)
  {
    printf("Sorry no node exists in list\n");
    return;
  }
  if(position == 1)
  {
    start = start->node;
    free(ptr1);
    printf("Node successfully deleted\n");
    return;
  }
  else
  {
    while (ptr1->node != NULL && i<position)
    {
      ptr2 = ptr1;
      ptr1=ptr1->node;
      i++;
    }
    if(i==position)
    {
      ptr2->node = ptr1->node;
      free(ptr1);
      printf("Node successfully deleted\n");
    }
    else
    {
      printf("Node at this this position doesn't exists\n");
    }
  }
}

void search()
{
  int number;
  struct listNode *ptr;
  int i=1;
  ptr = start;
  printf("Enter a number to search\n");
  scanf("%d", &number);
  while (ptr != NULL)
  {
      if(ptr->data == number)
      {
        printf("Number found at position %d", i);
        return;
      }
      i++;
      ptr = ptr->node;
  }
  printf("Number Not found\n");
}

void removeWholeLinkList()
{
  struct listNode *ptr;
  ptr = start;
  if(start == NULL)
  {
    printf("Link list is already empty\n");
    return;
  }
  else
  {
    while(ptr!=NULL)
    {
      start = start->node;
      free(ptr);
      ptr = start;
    }
    printf("Whole Link List successfully deleted\n");
  }
}
