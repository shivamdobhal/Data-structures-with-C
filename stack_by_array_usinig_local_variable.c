 //stack by array
#include <stdio.h>
#include <stdlib.h>
#define size 6

int push(int top,int stack[])
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
return top;
   }

  
}
int pop(int top,int stack[])
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
