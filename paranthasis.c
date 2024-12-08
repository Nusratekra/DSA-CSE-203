#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

bool isFull(int top)
{
    return top == MAX_SIZE - 1;
}

bool isEmpty(int top)
{
    return top == -1;
}

void push(char stack[], int *top, char item)
{
    if (isFull(*top))
        return;
    stack[++(*top)] = item;
}

char pop(char stack[], int *top)
{
    if (isEmpty(*top))
        return '\0';
    return stack[(*top)--];
}

bool areParenthesesBalanced(char exp[])
{
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, &top, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(top))
            {
                return false;
            }

            char topChar = pop(stack, &top);
            if ((exp[i] == ')' && topChar != '(') ||
                    (exp[i] == '}' && topChar != '{') ||
                    (exp[i] == ']' && topChar != '['))
            {
                return false;
            }
        }
    }

    return isEmpty(top);
}

int main()
{
    int choice;
    char exp[MAX_SIZE];

    printf("Menu:\n");
    printf("1. Check expression for balanced parentheses\n");
    printf("2. Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the expression: ");
            scanf("%s", exp);
            printf("%s is %s\n\n", exp, areParenthesesBalanced(exp) ? "Balanced" : "Unbalanced");
        }
        else if (choice == 2)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}
