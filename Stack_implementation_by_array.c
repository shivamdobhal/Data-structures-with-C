    //stack by array
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
