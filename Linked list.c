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









Question_2} Implement circular linked list using double pointers and call by address. {by local variables}
SOLUTION-
            //1.insert from front   2.insert from end    3.insert before the given element  4.insert afer the given element  5.delete from front    6.delete from end   
           // 7.delete after the given element      8. search and delete the given key    9.display
#include <iostream>
using namespace std;
struct node {
             int data;
             struct node *next;
            };



void insert_from_front(struct node **head,int value)
{
    struct node *newnode,*ptr;
    ptr=*head;
     newnode=(struct node*)malloc(sizeof(struct node));
    if(*head==NULL)
    {
        newnode->data=value;
        *head=newnode;         //IMPORTANT STEP AS IF THIS STEP DOESNOT COME HERE THEN ALL THE NODES OF THE LINKED LIST WILL BE NULL 
        newnode->next=*head;
        
    }
    else {
        while(ptr->next!=*head)
        {
            ptr=ptr->next;
        }
        newnode->data=value;
        newnode->next=*head;
        ptr->next=newnode;
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
          *head=newnode;
        newnode->next=*head;
      
    }
    else {
        newnode->data=value;
        
        while(ptr->next!=*head)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=*head;
       
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
    struct node *ptr=*head;
    if(*head==NULL)
    {
        cout<<"no node to delete";
    }
    else 
    {
        cout<<"deleted element="<<(*head)->data;
        while(ptr->next!=*head)
        {
            ptr=ptr->next;
        }
        ptr->next=(*head)->next;
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
        while(ptr->next!=*head)
        {   
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=*head;
        cout<<"deleted element="<<ptr->data;
        free(ptr);
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
 while(ptr->next!=*head)
 {
     cout<<ptr->data<<endl;
     ptr=ptr->next;
 }
 cout<<ptr->data<<endl;
}


int main(){
    
    int value,x;
    int key;
    struct node *head=NULL;
    int ch;
    while(1)
    {
       // cout<<"1.insert from front   2.insert from end    3.insert before the given element" <<endl;
       // cout<<" 4.insert afer the given element  5.delete from front    6.delete from end "<<endl;  
       // cout<<" 7.delete after the given element  8. search and delete the given key 9.display"<<endl;

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









Question_3} Implement doubly linked list using double pointers and call by address. {by local variables}
SOLUTION-

#include <iostream>
using namespace std;

struct node {
    struct node *previous;
    int data;
    struct node *next;
            };


void insert_begin(struct node **head,int value)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        newnode->previous=NULL;
        *head=newnode;
    }
    else
    {
        newnode->data=value;
        newnode->previous=NULL;
        newnode->next=*head;
        (*head)->previous=newnode;
        *head=newnode;
    }
}






void insert_end(struct node **head,int value)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        newnode->previous=NULL;
        *head=newnode;
    }
    else
    { 
     struct node *ptr;
     ptr=*head;
                         while(ptr->next!=NULL)
                        {
                                    ptr=ptr->next;
                        }
      newnode->data=value;
      newnode->next=NULL;
      newnode->previous=ptr;
      ptr->next=newnode;
    }   
}





void insert_before(struct node **head,int value,int key)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        newnode->previous=NULL;
        *head=newnode;
    }
    else
    { 
         struct node *ptr;
         ptr=*head;
            while(ptr->data!=key)
            {   
                  ptr=ptr->next;
            }
        newnode->data=value;
        newnode->next=ptr;
        newnode->previous=ptr->previous;
        ptr->previous->next=newnode;
        ptr->previous=newnode;
    } 
}







void insert_after(struct node **head,int value,int key)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        newnode->previous=NULL;
        *head=newnode;
    }
    else
    { 
         struct node *ptr;
        ptr=*head;
            while(ptr->data!=key)
            {
                ptr=ptr->next;
            }
        newnode->data=value;
        newnode->next=ptr->next;
        newnode->previous=ptr;
        ptr->next=newnode;
        ptr->next->previous=newnode;
    }         
}







void delete_begin(struct node **head)
{
    if(*head==NULL)
    {
        cout<<"underflow(no node to delete)";
    }
    else
    {
       cout<<"deleted :"<<(*head)->data;
       (*head)=(*head)->next;
       (*head)->previous=NULL;
    }
}







void delete_end(struct node **head)
{
    if(*head==NULL)
    {
        cout<<"underflow(no node to delete)";
    }
    else
    {
        struct node *ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        cout<<"deleted :"<<ptr->data;
        ptr->previous->next=NULL; 
    }
}




void search_and_delete(struct node **head,int key)
{
  if(*head==NULL)
    {
        cout<<"underflow(no node to delete)";
    }
 else
 {
  struct node *ptr=*head;
              while(ptr->data!=key)
              {
                    ptr=ptr->next;
               }
             
  if(ptr->data==key)
 {
    cout<<"key found and deleted successfully"<<endl;
 }
   cout<<"deleted"<<ptr->data;
   ptr->previous->next=ptr->next;
   ptr->next->previous=ptr->previous;
 }     
}





void display(struct node **head)
{
    struct node *ptr;
    ptr=*head;
      while(ptr!=NULL)
      {
         cout<<" "<<ptr->data;
         ptr=ptr->next;
      }
}



int main()
{    
    struct node *head;
    head=NULL;
    int ch;
    int x;
    int key;
    while(1)
    {
        cout<<"1.insert at beginning   2.insert at end    3.insert before"<<endl;
        cout<<"4.insert after   5.delete begin   6.delete end"<<endl;
        cout<<"7.search and delete   8. display"<<endl; 
        cout<<"enter your choice :";
        cin>>ch;

        if (ch==1)
        {
            
            cout<<"enter the value to be inserted :";
            cin>>x;
            insert_begin(&head,x);
         
        }



        if (ch==2)
        {
            
            cout<<"enter the value to be inserted :";
            cin>>x;
            insert_end(&head,x);
          
        }

        if (ch==3)
        {
          
            cout<<"enter the key before which you want to insert";
            cin>>key;
            cout<<"enter the value to be inserted ";
            cin>>x;
            insert_before(&head,x,key);
            
        }

        if (ch==4)
        {
          
            cout<<"enter the key after which you want to insert";
            cin>>key;
            cout<<"enter the value to be inserted ";
            cin>>x;
            insert_after(&head,x,key);
          
        }

         if (ch==5)
        {
            
            delete_begin(&head);
            
        }


         if (ch==6)
        {
            
            delete_end(&head);
            
        }

         if(ch==7)
         {
            cout<<"enter the key";
            cin>>key;
            search_and_delete(&head,key);
         }

        if(ch==8)
        {
            display(&head);
        } 

    }
    return 0;
}
       
