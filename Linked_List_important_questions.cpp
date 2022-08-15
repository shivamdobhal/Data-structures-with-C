QUESTION / PROBLEM STATEMENT 1]---------------------------------------------------a)-create a loop/cycle in linked list
                               ---------------------------------------------------b)-detect loop in linked list
                               ---------------------------------------------------c)-find beginning/ starting point of loop
                               ---------------------------------------------------d)- delete the loop
SOLUTION----Detecting loop using floyd loop detection algorithm.Floyd’s Cycle Detection algorithm is a two-pointer algorithm that is used to determine
             whether a loop exists or not in a given linked list. If a loop exists then using this algorithm we can also find out at which node the loop begins.
               time complexity=o(n)    space complexity=o(1)

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    };




 //inserting values in linked list from end
void insert(struct node **head,int value)  
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        *head=newnode;
    }
    else
    {
         newnode->data=value;
         struct node *ptr=*head;
         while(ptr->next!=NULL)
         {
            ptr=ptr->next;
         }
         ptr->next=newnode;
         newnode->next=NULL;
    }    
}


 
 

//creating loop/cycle in linked list
void create_loop(struct node **head,int key)
{
    struct node *ptr;
    ptr=*head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

struct node *temp;
    temp=*head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    ptr->next=temp;
    cout<<"loop created successfully!!!!!"<<endl;
}






//detect cycle using floyd cycle detection algo
struct node* detect_loop(struct node **head)
{
struct node *slow_ptr=*head;                              //slow pointer takes 1 step
struct node *fast_ptr=*head;                              //fast pointer takes 2 steps  
while(fast_ptr!=NULL && slow_ptr!=NULL && fast_ptr->next!=NULL)
{
    slow_ptr=slow_ptr->next;
    fast_ptr=fast_ptr->next->next;
         if(slow_ptr==fast_ptr)                   //if slow pointer is equal to fast pointer then it means that a loop/cycle is present
         {
                     // cout<<"loop/cycle present"<<endl;
            return slow_ptr;
            break;
         }
}
return NULL;
}




//finding the starting node of cycle
struct node* starting_pt(struct node **head)
{
struct node *ptr=detect_loop(head);
struct node *start=*head;
while(ptr!=start)
{
    ptr=ptr->next;
    start=start->next;
}
cout<<"starting node : "<<start->data;
cout<<endl;
return start;
}






struct node* delete_loop(struct node **head)
{
struct node *ptr=detect_loop(head);
struct node *temp=starting_pt(head);
     while(ptr->next!=temp)
     {  
       ptr=ptr->next;
     }
    
ptr->next=NULL;
cout<<"loop/cycle deleted"<<endl;
}





void display(struct node **head)
{
struct node *ptr=*head;
while(ptr!=NULL)
{
    cout<<" "<<ptr->data;
    ptr=ptr->next;
}
cout<<endl;

}





int main(){
    
    struct node *head;
    head=NULL;
    int ch;
    int x;
    int key;
            cout<<"1.insert     2.create loop    3.loop detection "<<endl;
        cout<<"4.find starting pt    5.delete loop    6.display"<<endl;
    while(1)
    {
 
        cout<<"enter your choice :";
        cin>>ch;

        if (ch==1)
        {       
            cout<<"enter the value to be inserted :";
            cin>>x;
            insert(&head,x);     
        }

         if (ch==2)
        {
            cout<<"enter the data from where you want to attach last node:";
            cin>>key;
            create_loop(&head,key);         
        }

        if (ch==3)
        {
            detect_loop(&head);        
        }

        if (ch==4)
        {
            starting_pt(&head);           
        }

        if (ch==5)
        {
            delete_loop(&head);          
        }

         if (ch==6)
        {            
            display(&head);
            
        }
    }
}











QUESTION 2} FIND AND RETRIEVE THE MIDDLE ELEMENT FROM THE LINKED LIST.
  
  SOLUTION = we can find middle element by two methods --1.by using two pointers
                                                         2.by finding the length and then iterate to the middle
                                                         
            1.in two pointer method one pointer is slow pointer and one pointer is fast pointer.slow pointer takes one step and 
                 slow pointer takes two steps till fast_ptr doesnot reach to NULL.
                               then return the slow_ptr->data(i.e,middle element)
  
          if elements are odd-----middle is=mid
          if elements are even-----middle is=mid+1
 
            
            
            
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};


void insert(struct node **head,int value)                     //from end
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(*head==NULL)
    {
        newnode->data=value;
        newnode->next=NULL;
        *head=newnode;
    }
    else
    {
         newnode->data=value;
         struct node *ptr=*head;
         while(ptr->next!=NULL)
         {
            ptr=ptr->next;
         }
         ptr->next=newnode;
         newnode->next=NULL;
    }    
}



void find_middle(struct node **head)
{
	if(*head==NULL)
	{
		cout<<"underflow";
	}
    
   else{
		      struct node *ptr=*head;
		      struct node *temp=*head;
              int a=0;              //a gives us the correct length of linked list

		              while(ptr!=NULL)
		              {
			                  ptr=ptr->next;	
                        a++;	     //for calculating length
                  }    
cout<<"length = "<<a<<endl;  
     
int mid=a/2;
     
                while(mid!=0)    //traverse till mid doesnot become 0
                {
                temp=temp->next;
                 mid--;
                }
cout<<"middle element is -->"<<temp->data<<endl;
}
}


void two_pointer_method(struct node** head)
{
    struct node *slow_ptr=*head;
    struct node *fast_ptr=*head;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;

    }
    cout<<"middle is "<<slow_ptr->data;
}




void display(struct node **head)
{
struct node *ptr=*head;
while(ptr!=NULL)
{
    cout<<" "<<ptr->data;
    ptr=ptr->next;
}
cout<<endl;

}




int main()
{
struct node *head;
head=NULL;
int x,ch;

    while(1)
    {
        cout<<"enter ch :";
        cin>>ch;

          if(ch==1)
          {
	            cin>>x;
            	insert(&head,x);
          }

          if (ch==2)
          {
	            find_middle(&head);
          }


          if (ch==3)
          {
	            two_pointer_method(&head);
          }

          if (ch==4)
          {
	            display(&head);
          }
}
    return 0;
}           
