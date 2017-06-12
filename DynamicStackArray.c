#include<stdio.h>
#include<malloc.h>

struct DynamicStack
{
  int top;
  int capacity;
  int *array;
};

struct DynamicStack * createStack()
{
  struct DynamicStack *stack = (struct DynamicStack *)malloc(sizeof(struct DynamicStack));
  if(!stack)
  {
    printf("Overflow in memory\n");
    return NULL;
  }
  stack->capacity = 1; //starting with capacity one.
  stack->top = -1;
  stack->array = (int *)malloc(stack->capacity * sizeof(int));
  if(!(stack->array))
  {
    printf("Overflow in memeory\n");
    return NULL;
  }
  return stack;
}

void reallocateStack(struct DynamicStack **stack)
{
  (*stack)->capacity = ((*stack)->capacity)*2;
  realloc((*stack)->array, (*stack)->capacity);
}

int isStackEmpty(struct DynamicStack *stack)
{
  return (stack->top == -1);
}

int isStackFull(struct DynamicStack *stack)
{
  return (stack->top == stack->capacity - 1);
}

void push(struct DynamicStack **stack, int value)
{
  if(isStackFull(*stack))
    reallocateStack(stack);
  (*stack)->top = (*stack)->top + 1;
  (*stack)->array[(*stack)->top] = value;
}

int pop(struct DynamicStack **stack)
{
  int resultingValue;
  if(isStackEmpty(*stack))
  {
    printf("Underflow\n");
    return 0;
  }
  resultingValue = (*stack)->array[(*stack)->top];
  (*stack)->top = (*stack)->top - 1;
  return resultingValue;
}

void traverse(struct DynamicStack *stack)
{
  for(int i = stack->top; i>-1; i--)
  {
    printf("%d-->", stack->array[i]);
  }
  printf("\n");
}

void main(int argc, char const *argv[])
{
  printf("Compiling successfully\n");
  struct DynamicStack *stack = createStack();
  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  push(&stack, 7);
  push(&stack, 11);
  traverse(stack);
}
