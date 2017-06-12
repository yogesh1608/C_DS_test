//This is the implementation of stack with the help of link list.
#include<stdio.h>
#include<malloc.h>

struct Stack
{
  char data;
  struct Stack *next;
};

struct Stack * createStack()
{
  return NULL;
}

int isStackEmpty(struct Stack *top)
{
    if(top == NULL)
    {
      return 0;
    }
    else
    {
      return 1;
    }
}

void push(struct Stack **top, char value)
{
  struct Stack *stackNode = (struct Stack *)malloc(sizeof(struct Stack));
  if(!stackNode)
  {
    printf("Running out of memory\n");
    return;
  }
  stackNode->data = value;
  if((*top) == NULL)
  {
    stackNode->next = NULL;
    *top = stackNode;
  }
  else
  {
    stackNode->next = *top;
    *top = stackNode;
  }
}

char pop(struct Stack **top)
{
  if(isStackEmpty(*top))
  {
    printf("Underflow\n");
    return -1;
  }
  int value = (*top)->data;
  struct Stack *tempStackNode = *top;
  *top = (*top)->next;
  free(tempStackNode);
  return value;
}

void traverse(struct Stack *top)
{
  while(top)
  {
    printf("%c", top->data);
    if(top->next != NULL)
    {
      printf("-->");
    }
    top = top->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  printf("Compiling successfully\n");
  struct Stack *stack = createStack();
  push(&stack, 'a');
  push(&stack, 'b');
  traverse(stack);
  return 0;
}
