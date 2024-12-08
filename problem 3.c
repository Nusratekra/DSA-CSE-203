#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void insertEnd(struct node *head,int data) //insert at the end
{
    struct node *ptr,*temp;
    ptr = head;  //head assign to ptr
    temp = malloc(sizeof(struct node));//temp node creation
    temp->data=data;
    temp->link = NULL;
    //to treverse
    while(ptr->link != NULL)
    {
        ptr =ptr->link;
    }
    ptr->link = temp;
}
void update(struct node* head,int data,int pos){//at any update
 struct node *ptr = head;

    struct node *temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->link = NULL;

    pos--;
    while(pos!=0){
        ptr =ptr->link;
        pos--;
    }
    ptr->data = temp->data;

}
void print(struct node *head) //print
{
    if(head == NULL)
    {
        printf("Empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
void delEnd(struct node *head){ //delete from last
  if(head == NULL){
    printf("The list is empty");
  }
  else if(head->link == NULL){
    free(head);
    head = NULL;
  }
  else{
    struct node *temp = head;
    while(temp->link->link != NULL){
        temp =temp->link;
    }
    free(temp->link);
    temp->link = NULL;
  }

}

int main()
{
    struct node *head = malloc(sizeof(struct node));// node creation
    printf("First element of Uap id:\n");
    head->data=2;
    head->link = NULL;
    while(1){
            printf("\nThe Menu :\n1.insert\n2.Delete\n3.Update\n4.Print\n5.Exit\n");
        int option;
        printf("Enter the option: ");
        scanf("%d",&option);
        if(option == 1){
                int data;
            printf("\nThe element of my id is: ");
            scanf("%d",&data);
            insertEnd(head,data);
        }
        else if(option == 2){
            printf("\nRemove a element from the Uap id.\n");
            delEnd(head);
        }
        else if(option == 3){
                int data,position;
            printf("\nEnter the updated position: ");
            scanf("%d",&position);
            printf("\nEnter the updated data: ");
            scanf("%d",&data);
            update(head,data,position);

        }
        else if(option == 4){
                  print(head);
                }
                else if(option == 5){
                  printf("exit.....");
                  break;
                }
                else{
                printf("Invalid choice.....");
                }

    }

}
