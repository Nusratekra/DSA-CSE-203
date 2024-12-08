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
struct node* addBeg(struct node* head,int data) //atTheBeg
{
    struct node* ptr= malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
}
void addAnyPos(struct node* head,int data,int pos){//at any pos
 struct node *ptr = head;

    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link = NULL;

    pos--;
    while(pos!=1){
        ptr =ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
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
struct node* delBeg(struct node *head){// delete from beg
  if(head == NULL){
    printf("List is already empty.\n");
  }
  else{
    struct node *temp =head;
    head = head->link;
    free(temp);
    temp= NULL;
  }
  return head;
}
void delAnyPos(struct node **head,int pos){
  struct node *current = *head;
  struct node *previous = *head;
  if(*head == NULL){
    printf("List is empty\n");
  }
  else if(pos == 1){
    *head = current->link;
    free(current);
    current= NULL;
  }
  else{
    while(pos !=1){
        previous = current;
        current = current->link;
        pos --;

    }
    previous->link=current->link;
    free(current);
    current =NULL;
  }
}
int main()
{
    struct node *head = malloc(sizeof(struct node));// node creation
    printf("the list;\n");
    head->data=4;
    head->link = NULL;

    insertEnd(head,9);
    insertEnd(head,14);
    insertEnd(head,19);
    print(head);

    head = addBeg(head,20);
    print(head);
    addAnyPos(head,17,5);
    print(head);
    printf("After update:\n");
    update(head,6,3);
    print(head);
    printf("After delete from last:\n");
    delEnd(head);
    print(head);
    printf("After delete from beg:\n");
    head = delBeg(head);
    print(head);
    printf("After delete in that position:\n");
    delAnyPos(&head,3);
    print(head);
}
