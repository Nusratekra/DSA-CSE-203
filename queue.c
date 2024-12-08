#include<stdio.h>
#define SIZE  5
int queue[SIZE],front =-1,rear =-1;
void enQueue(int value)
{
    if(rear == SIZE )
        printf("OVERFLOWING ");
    else if (front ==-1&& rear ==-1)
    {
        front=rear=0;
        queue[rear]=value;
    }
    else
    {
        rear++;
        queue[rear]=value;
    }
}
void deQueue()
{
    if(front==-1&&rear==-1)
    {
        printf("underflow");
    }
    else if (front == rear)
    {
        front = rear=-1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(front ==-1&&rear ==-1)
    {
        printf("NULL\n");
    }
    else
    {
        for(int i=front; i<= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}
void isFull()
{
    if(rear == SIZE)
        printf("full");
    else
    {
        printf("NOT FULL");
    }
}
void isEmpty()
{
    if(front==-1 ||front>rear)
    {
        printf("empty");
    }
    else
        printf("not empty");
}
int main()
{
    int option;
    while(1)
    {
          printf("****MANU****\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.isFull\n6.isEmpty\n6.Exit\n");

        printf("Enter the option :");
        scanf("%d",&option);
        if(option == 1)
        {
            int element;
            printf("\nThe element is:");
            scanf("%d",&element);
            enQueue(element);
        }
        else if(option == 2)
        {
            deQueue();
        }
        else if(option == 3)
        {
            printf("\nThe queue is:");
            display();
        }
        else if(option == 4)
        {
            printf("\nThe peek element is:");
            peek();
        }
        else if(option==5)
        {
            printf("\nThe queue is ");
            isFull();
        }
        else if(option==6)
        {
            printf("\nThe queue is ");
            isEmpty();
        }
        else if(option == 7)
        {
            printf("\nExitting...");
        }
        else
        {
            printf("\nInvalid option.....Try again\n");
        }
    }
}
