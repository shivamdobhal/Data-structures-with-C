QUESTION-1]Queue by using array and  by local variable
#include <stdio.h>                              //insertion from front
#include <stdlib.h>                             //deletion from rear
#define size 6

int enqueue(int front,int queue[])
{int x;

    if(front>=size-1)
    printf("overflow");

    else
    {
        printf("pushes : ");
        scanf("%d",&x);
        front++;
        queue[front]=x;
    return front;
    }

   }

  

int dequeue( int front,int rear,int queue[])
{
   if(front==-1)
   printf("underflow");
   else
   {
       printf("popped elemnt : %d",queue[rear+1]);
       rear++;
       return rear;
   }
}
int peek(int rear,int queue[])
{
  printf("top elemnt : %d",queue[rear+1]);
}


int isfull(int front)
{
   if(front>=size-1)
    printf("overflow");

}


int isempty(int front) 
{
   if(front==-1)
   printf("underflow");
}


int display(int rear,int front,int queue[])
{
int i;
for(i=rear+1 ; i<=front ;  i++)
{
printf("%d ",queue[i]);
}
}

int main()
{
 int rear=-1;
 int front=-1;
 int queue[size];

  while(1)
    {
        int ch;
        printf("enter your choice:  ");
        scanf("%d",&ch);
if(ch==1)
        front=enqueue(front,queue);
else if(ch==2)
        rear=dequeue(front,rear,queue);
 else if(ch==3)
        peek(rear,queue);
 else if(ch==4)
        isempty(front) ;
 else if(ch==5)
        isfull(front) ;
 else if(ch==6)
        display(rear,front,queue);     
    }
 return 0;
}





QUESTION-2] queue  implementation by using linked list [using double pointers ] 
SOLUTION->queue can be implemented  by linked list using two ways->1.insertion from begin and deletion from last 
                                                                   2.insertion from last and deletion from begin 
=> But I am doing  insertion from last and deletion from begin
#include <stdio.h>
#include <stdlib.h>         //for malloc() function

struct node{
            struct node *next;
            int data;
           };                                         //insert from rear  & deletion from front



int insert(struct node **head,int value)
{
    struct node *newnode;
    newnode=(struct node* )malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
      *head = newnode;
    }
    else{
                struct node *ptr=*head;
                    while(ptr->next!=NULL)
                    {
                    ptr=ptr->next;
                    }   
        newnode->data=value;
        newnode->next=NULL;
        ptr->next= newnode;
        }
}



void delete(struct node **head)
{
struct node *ptr=*head;
        if(*head==NULL)
        printf("no node to delete");
else
    {
    printf("deleted value is %d\n",(*head)->data);
    *head=ptr->next;
    }
}


void display(struct node **head)
{
    struct node *ptr;
    ptr=*head;
    int i=0;
        while(ptr!=NULL)
        {
            printf(" %d ",ptr->data);
            ptr=ptr->next;
        }
}
 

int main()
 {
 struct node *head;
 head=NULL;
  insert(&head,10);
  insert(&head,20);
  insert(&head,30);
  insert(&head,40);
  insert(&head,50);
  delete(&head);
  delete(&head);
  display(&head);
  return 0;
 }
    
