Question-1}Implement singly linked list using double pointer and local variables using c++.
            //1.insert from front    2.insert from end   3.insert before the given element    4.insert after the given element      5.delete from front  6.delete from end
            //7.delete after the given element  8. search the key and delete if founded. 
    SOLUTION-
#include <iostream>
using namespace std;

struct node {
               int data;
               struct node *next;

            };


void insert_from_front(struct node **head,int value)
{
     struct node *newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(head==NULL)
     {
        newnode->data=value;
        newnode->next=NULL;
        *head=newnode;
     }
    else
     {
        newnode->data=value;
        newnode->next=*head;
        *head=newnode;
     }
}


void insert_from_end(struct node **head,int value)
{
    struct node *newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=*head;
    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        *head=newnode;
    }
    else
    {
        newnode->data=value;
        newnode->next=NULL;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}


void insert_before(struct node **head,int value,int x)
{
     struct node *newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     struct node *ptr,*temp;
     ptr=*head;
   while(ptr->data!=x)
   {
       temp=ptr;
       ptr=ptr->next;
   }
        newnode->data=value;
        newnode->next=temp->next;
        temp->next=newnode;
}



void insert_after(struct node **head,int value,int x)
{
 struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
     struct node *ptr,*temp;
     ptr=*head;
   while(ptr->data!=x)
   {
       temp=ptr;
       ptr=ptr->next;
   }
   newnode->data=value;
   newnode->next=ptr->next;
   ptr->next=newnode;
}


void delete_front(struct node **head)
{
    if(*head==NULL)
    {
        cout<<"no node to delete";
    }
    else 
    {
        cout<<"deleted element="<<(*head)->data;
        *head=(*head)->next;
    }   
}



void delete_end(struct node **head)
{
  struct node *ptr,*temp;  
  ptr=*head;
    if(*head==NULL)
    {
        cout<<"no node to delete";
    }
    else 
    {
        while(ptr->next!=NULL)
        {   
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        cout<<"deleted element="<<ptr->data;
    }
}





void delete_after(struct node **head,int x)
{
 struct node *ptr,*temp;
 ptr=*head;
  temp=ptr;
  while(temp->data!=x)
  {
      temp=ptr;
      ptr=ptr->next;
  }
temp->next=ptr->next;
cout<<"deleted element-- "<<ptr->data;
}




void delete_search_and_delete(struct node **head,int key)    //enter the no. to be deleted and traverse till you find the given key and if key found then delete the given key
{
struct node *ptr,*temp;
ptr=*head;
while(ptr->data!=key)
{
    temp=ptr;
    ptr=ptr->next;
}
temp->next=ptr->next;

if(ptr->data==key)
{
    cout<<"key found and deleted successfully"<<endl;
}
}



void display(struct node **head)
{
 struct node *ptr=*head;
 while(ptr!=NULL)
 {
     cout<<ptr->data<<endl;
     ptr=ptr->next;
 }
}







int main(){
    
    int value,x;
    int key;
    struct node *head=NULL;
    int ch;
    while(1)
    {
        cout<<"1.insert from front   2.insert from end    3.insert before the given element" <<endl;
        cout<<" 4.insert afer the given element  5.delete from front    6.delete from end "<<endl;  
        cout<<" 7.delete after the given element  8. search and delete the given key 9.display"<<endl;

        cout<<"enter your choice :";
        cin>>ch; 


        if(ch==1)
        {
            cout<<endl<<"enter the given no. which you wanted to push";
            cin>>value;

            insert_from_front(&head,value);
        }

      else if(ch==2)
        {
            cout<<endl<<"enter the given no. which you wanted to push";
            cin>>value;

            insert_from_end(&head,value);
        }

      else if(ch==3)
        {
            cout<<"enter the value you want to insert";
            cin>>value;
            cout<<endl<<"enter the number before which you wanted to push an element::";
            cin>>x;
            
            insert_before(&head,value,x);
        }

      else if(ch==4)
        {
            cout<<"enter the value you want to insert";
            cin>>value;
            cout<<endl<<"enter the  number after which you wanted to push an element::";
            cin>>x;

            insert_after(&head,value,x);
        }

       else if(ch==5)
        {
            delete_front(&head);
        }

      else if(ch==6)
        {
            delete_end(&head);
        }

     else if(ch==7)
        {
            cout<<endl<<"enter the value after which you wanted to delete the element";
            cin>>x;
            delete_after(&head,x);
        }
      
        else if(ch==8)
        {
            cout<<"enter the key which you wanted to search and delete::";
            cin>>key;
            delete_search_and_delete(&head,key);
        }

        else if(ch==9)
        {
            display(&head);
        }
    }
    return 0;
}
