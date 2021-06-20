#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int capacity;
    int top;
    int *ptr;
} Stack;

Stack* createStack(int);
void push(Stack*, int);
int pop(Stack*);
char* infix_to_postfix(char *);
int precedence(char);
int is_operator(char);

int main()
{
    Stack *stack = NULL;
    stack = createStack(10);
    char infix[30] = "";
    char postfix[30] = "";
    int i = 0, a, b, convert, cal = 0;

    gets(infix);

    InfixToPostfix(infix, postfix);

    while(postfix[i])
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            convert = postfix[i] - '0';
            push(stack, convert);
        }
        else if(postfix[i] == '^')
        {
            a = pop(stack);
            b = pop(stack);

            cal = pow(b, a);
            push(stack, cal);
        }
        else if(postfix[i] == '/')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b / a;
            push(stack, cal);
        }
        else if(postfix[i] == '*')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b * a;
            push(stack, cal);
        }
        else if(postfix[i] == '+')
        {
            a = pop(stack);
            b = pop(stack);

            cal = b + a;
            push(stack, cal);
        }
        else if(postfix[i] == '-')
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

//conversion infix to postfix code start
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;
    Stack *stack = NULL;
    stack = createStack(10);
    push(stack, '(');                               /* push '(' onto stack */
    strcat(infix_exp,")");                  /* add ')' to infix expression */

    i=0;
    j=0;
    item=infix_exp[i];         /* initialize before loop*/

    while(item != '\0')        /* run loop till end of infix expression */
    {
        if(item == '(')
            push(stack, item);
        else if( isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;              /* add operand symbol to postfix expr */
            j++;
        }
        else if(is_operator(item) == 1)        /* means symbol is operator */
        {
            x=pop(stack);
            while(is_operator(x) == 1 && precedence(x)>= precedence(item))
            {
                postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
                j++;
                x = pop(stack);                       /* add them to postfix expresion */
            }
            push(stack,x);
            /* because just above while loop will terminate we have
            oppped one extra item
            for which condition fails and loop terminates, so that one*/

            push(stack, item);                 /* push current oprerator symbol onto stack */
        }
        else if(item == ')')         /* if current symbol is ')' then */
        {
            x = pop(stack);                   /* pop and keep popping until */
            while(x != '(')                /* '(' encounterd */
            {
                postfix_exp[j] = x;
                j++;
                x = pop(stack);
            }
        }
        i++;

        item = infix_exp[i]; /* go to next symbol of infix expression */
    } /* while loop ends here */


    postfix_exp[j] = '\0';

}

int is_operator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 1;
    return 0;
}

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;

    return 0;
}
//conversion infix to postfix code end

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


