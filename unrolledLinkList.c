//A program to impelement efficient unrolled link list.
#include<stdio.h>
#include<malloc.h>
int maxBlockSize = 4;
int presentMaxIndex;
struct listNode
{
  int data;
  struct listNode *next;
};

struct linkedBlock
{
  struct listNode *head;
  int nodeCount;
  struct linkedBlock *next;
};

struct linkedBlock *headBlock = NULL;

//Creating an empty block
struct linkedBlock * newLinkedBlock()
{
  struct linkedBlock *block = (struct linkedBlock *)malloc(sizeof(struct linkedBlock));
  block->head = NULL;
  block->next = NULL;
  block->nodeCount = 0;
  return block;
}

//Creating a new node
struct listNode * newListNode(int value)
{
  struct listNode *tempNode = (struct listNode *)malloc(sizeof(struct listNode));
  tempNode->next = NULL;
  tempNode->data = value;
  return tempNode;
}


//This function will search the index and update the provided linkedBlock and listNode as according.
void search(int index, struct linkedBlock **tempLinkedBlock, struct listNode **tempListNode)
{
  //For finding the head block
  printf("Reaching here : %d %d \n", index, maxBlockSize);
  int k;
  int blockIndex = (index + maxBlockSize)/maxBlockSize;
  struct linkedBlock *tempBlock = headBlock;
  while (--blockIndex)
  {
    tempBlock = tempBlock->next;
  }
  *tempLinkedBlock = tempBlock;
  struct listNode *tempNode = tempBlock->head;
  //For finding the node inside the searched block
  index = index%maxBlockSize;
  //For a case in which last node of that block is searched
  if (k==0)
  {
    k = maxBlockSize;
  }
  k = tempBlock->nodeCount - index + 1;
  while (k--)
  {
    tempNode = tempNode->next;
  }
  *tempListNode = tempNode;
  return;
}

void shift(struct linkedBlock *A)
{
  struct linkedBlock *B;
  struct listNode *temp;
  while(A->nodeCount > maxBlockSize)
  {
    if(A->next == NULL)
    {
      temp = A->head->next;
      A->head->next = A->head->next->next;
      A->nodeCount--;
      B = newLinkedBlock();
      B->head = temp;
      B->head->next = B->head;
      B->nodeCount++;
    }
    else
    {
      B = A->next;
      temp = A->head->next;
      A->head->next = A->head->next->next;
      A->nodeCount--;
      temp->next = B->head->next;
      B->head->next = temp;
      B->head = temp;
      A = B;
    }
  }
}

void addElement(int index, int value)
{
  struct linkedBlock *tempLinkedBlock;
  struct listNode *tempNode;
  struct listNode *ptr;
  //If whole list is empty
  if(headBlock == NULL)
  {
    headBlock = newLinkedBlock();
    headBlock->head = newListNode(value);
    headBlock->head->next = headBlock->head;
  }
  //special case for index, to be less complexed
  else if(index == 0)
  {
    struct listNode *newNode;
    newNode = newListNode(value);
    newNode->next = headBlock->head->next;
    headBlock->head->next = newNode;
    headBlock->head = newNode;
    shift(headBlock);
  }
  //For every excluded case
  else
  {
    search(index, &tempLinkedBlock, &tempNode);
    struct listNode *newNode = newListNode(value);
    newNode->next = tempNode->next;
    tempNode->next = newNode;
  }
}

int getValueInIndex(int index)
{
  struct linkedBlock *tempLinkedBlock;
  struct listNode *tempListNode;
  search(index, &tempLinkedBlock, &tempListNode);
  return tempListNode->data;
}

int main(int argc, char const *argv[])
{
  addElement(0, 13);
  addElement(1, 43);
  addElement(2, 100);
  printf("%d\n", getValueInIndex(0));
  printf("%d\n", getValueInIndex(1));
  return 0;
}
