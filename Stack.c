   QUESTION-1]stack by array  using global variables
#include <stdio.h>
#include <stdlib.h>
#define size 6
int push();            //entering the elements
int pop();            //deletion  of topmost element
int peek();         //display topmost element of the stack
 int isempty();    //checks that the stack is empty or not
 int isfull();    //checks that the stack is full or not
 int display();    //it will display all the elements of stack
int top =-1;
int stack[size];



int main()
{
  while(1)
    {
        int ch;
        printf("enter your choice:  ");
        scanf("%d",&ch);
if(ch==1)
      push();
else if(ch==2)
        pop();
 else if(ch==3)
        peek();
 else if(ch==4)
        isempty();
 else if(ch==5)
        isfull();
 else if(ch==6)
        display();     
     }
 return 0;
}


int push()
{
    int el;
    if(top>size-1)
    printf("stack is full");
    else
   { 
       printf("enter the value to be pushed into the stack: \n");
    scanf("%d",&el);
    top++;
stack[top]=el;
   }

  
}
int pop()
{
    int e;
    if(top==-1)
    {
        printf("no element left to delete");

    }
else 
  {
 e=stack[top];
 top--;  
 printf("the deleted element is %d\n",e);
  }
}


int peek()
{
    printf("topmost elements is %d\n",stack[top]);
}


int isfull()
{
    if(top==size-1)
    printf("stack is full");
    else 
    printf("stack is not full");
}


int isempty()
{
    if(top==-1)
    printf("stack is empty");
    else 
    printf("stack is not empty");
}


int display()
{int i=0;
    for(i=0;i<=top;i++)
    printf("%d ",stack[i]);
}






QUESTION-2]-Stack_implementation_by_array using local variable
solution-
#include <stdio.h>
#include <stdlib.h>
#define size 6

int push(int top,int stack[])
{
    int value;
    if(top>size-1)
    printf("stack is full");
    else
   { 
       printf("enter the value to be pushed into the stack: \n");
    scanf("%d",&value);
    top++;
stack[top]=value;
return top;
   }

  
}
int pop(int top,int stack[])
{
   
    if(top==-1)
    {
        printf("no element left to delete");

    }
else 
  {
 top--;  
 printf("the deleted element is %d\n",stack[top]);
 return top;
  }
}


int peek(int top,int stack[])
{
    printf("topmost elements is %d\n",stack[top]);
}


int isfull(int top)
{
    if(top==size-1)
    printf("stack is full");
    else 
    printf("stack is not full");
}


int isempty(int top)
{
    if(top==-1)
    printf("stack is empty");
    else 
    printf("stack is not empty");
}


int display(int top,int stack[])
{int i=0;
    for(i=0;i<=top;i++)
    printf("%d ",stack[i]);
}

int main()
{
    int top =-1;
int stack[size];
  while(1)
    {
        int ch;
        printf("enter your choice:  ");
        scanf("%d",&ch);
if(ch==1)
      top=push(top,stack);
else if(ch==2)
       top=pop(top,stack);
 else if(ch==3)
        peek(top,stack);
 else if(ch==4)
        isempty( top);
 else if(ch==5)
        isfull( top);
 else if(ch==6)
        display( top, stack);     
     }
 return 0;
}




QUESTION-3] stack implementation using linked list [using local variables and double pointers]
//stack can be implemented using linked list using two ways:-  1.insertion and deletion by end
//                                                             2.insertion and deletion in beginning
solution-
 #include <stdio.h>
 #include <stdlib.h>

struct node{
    int data;
    struct node *next;
           };


void insert(struct node **head,int value)          //insertion at last/end
{
struct node *newnode;
newnode=(struct node* )malloc(sizeof(struct node));

if(*head==NULL)
{
    newnode->data=value;
    newnode->next=NULL;
    *head=newnode;
}
else
    {
    struct node *ptr;                                      //new pointer  created so that the value of the head is not lost
    ptr=*head;

        while(ptr->next!=NULL)
       {
            ptr=ptr->next;

       }
      newnode->data=value;
      newnode->next=NULL;
     ptr->next=newnode;
   }
}


void delete(struct node **head)                      //deletion from last
{
    struct node *temp,*ptr;
    ptr=*head;
    if(*head==NULL)
     {
       printf("no element to delete");
    } 
    else    
    {
       while(ptr->next!=NULL)
    {
        temp=ptr;
            ptr=ptr->next;

    }
printf("deleted value %d\n",ptr->data);
  temp->next=NULL;
  
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
