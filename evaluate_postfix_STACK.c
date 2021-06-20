#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    int capacity;
    int top;
    int *ptr;
} Stack;

Stack * createStack(int);
void push(Stack*, int);
int pop(Stack*);

int main()
{
    Stack *stack = NULL;
    stack = createStack(10);
    char pos_exe[30] = "";
    int i = 0, a, b, convert, cal = 0;

    gets(pos_exe);

    while(pos_exe[i])
    {
        if(pos_exe[i] >= '0' && pos_exe[i] <= '9')
        {
            convert = pos_exe[i] - '0';
            push(stack, convert);
        }
        else if(pos_exe[i] == '^')
        {
            a = pop(stack);
            b = pop(stack);

            cal = pow(b, a);
            push(stack, cal);
        }
        else if(pos_exe[i] == '/')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b / a;
            push(stack, cal);
        }
        else if(pos_exe[i] == '*')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b * a;
            push(stack, cal);
        }
        else if(pos_exe[i] == '+')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b + a;
            push(stack, cal);
        }
        else if(pos_exe[i] == '-')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b - a;
            push(stack, cal);
        }

        i++;
    }

    printf("%d ", pop(stack));

    return 0;
}

void push(Stack *stack, int item)
{
    if(stack->top + 1 == stack->capacity)
        printf("Overflow");
    else
    {
        stack->top += 1;
        stack->ptr[stack->top] = item;
    }
}

int pop(Stack *stack)
{
    int item = -1;

    if(stack->top == -1)
        return item;
    else
    {
        item = stack->ptr[stack->top];
        stack->top -= 1;
    }
    return item;
}

Stack * createStack(int cap)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->capacity = cap;
    s->top = -1;
    s->ptr = (int*)malloc(sizeof(int) * cap);
    return s;
}

