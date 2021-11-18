 // Queue by using array and  by local variable
#include <stdio.h>
#include <stdlib.h>
#define size 6

int enqueue(int front,int queue[])
{int x;

    if(front>=size-1)
    printf("overflow");

    else
    {
        printf("pushes : ");
        scanf("%d",&x);
        // stack[++top]=x;
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
