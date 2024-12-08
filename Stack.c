#include<stdio.h>
#define size 5
int stack[size];
int top = -1;
void isFull()
{
   if(top == 4){
    printf("Full\n");
   }
   else{
    printf("Not full\n");
   }
}
void isEmpty()
{
    if(top == -1){
        printf("Empty\n");
    }
    else{
        printf("Not empty\n");
    }
}
void push(int element)
{
    if(top == size-1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]= element;
    }
}
void pop()
{
    if(top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        top--;
    }
}
void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The peek element is %d\n",stack[top]);
    }
}
void display()
{
    if(top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(int i = top; i>= 0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}
int main()
{
    while(1)
    {
        printf("\n1.isFull\n2.isEmpty\n3.push\n4.pop\n5.display\n6.peek\n7.exit\n");
        int option;
        printf("The option is : ");
        scanf("%d",&option);

        if(option == 1)
        {   isFull();


        }
        else if(option == 2)
        {
            isEmpty();

        }
        else if(option == 3){
            int element;
            printf("The element is :");
            scanf("%d",&element);
            push(element);
        }
        else if(option == 4){
            pop();
        }
        else if(option == 5){
            display();
        }
        else if(option == 6){
            peek();
        }
        else if(option == 7){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid choice....Try again\n");
        }
    }
}
