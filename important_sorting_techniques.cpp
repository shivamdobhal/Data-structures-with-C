1.SELECTION SORT------------------------------------------------------------------------------------------------------------------------------------------------------- 
  =>find minimum and swap it from starting.
  -------------------------------------------------------------------------IN JAVA-------------------------------------------------------------------------------------           
  import java.util.Scanner;
  public class sel {
    public static void main(String args[])
	{
           Scanner sc=new Scanner(System.in);
           int size,arr[],temp;
           System.out.print("enter the size of the array : ");
           size=sc.nextInt();
           arr=new int[size];                 // ASSIGNING SIZE TO ARRAY
 
         for(int i=0;i<size;i++)
           {
              arr[i]=sc.nextInt();               //INPUTTING UNSORTED ARRAY 
           }
         
          int min;
          int position=0;                //FOR KEEPING THE INDEX OF MIN          
      
        for(int i=0;i<size-1;i++)                                      
           {  min = arr[i];
	      position=i;                         //important step
              for(int j=i+1;j<size;j++)
              {     
	      	       if(arr[j]<min)                    // FINDING MIN
                 {
                            min=arr[j];
  		            position=j;
 		          }
               }
               	temp=arr[i];		                   //SWAPPING
		        arr[i]=arr[position];                             //SWAPPING
		       arr[position]=temp;                      //SWAPPING
            }
   
       System.out.println("After selection sort: ");     
        for(int i=0;i<size;i++)
        {
            System.out.print(" "+arr[i]);
        }
}
}

 

 -------------------------------------------------------------------------IN C++-----------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main(){
    
 int size,temp,min,position=0;
          cout<<"enter the size of the array : ";
           cin>>size;
          int arr[size]; 
         for(int i=0;i<size;i++)
           {
              cin>>arr[i];
           }
        
        for(int i=0;i<size-1;i++)
           {  min = arr[i];
	     position=i;
              for(int j=i;j<size;j++)
              {     
		       if(arr[j]<min)
                 {
                            min=arr[j];
  		            position=j;
 		          }
               }
                	temp=arr[i];		
		        arr[i]=arr[position];
		       arr[position]=temp;
            }
   
    cout<<"After selection sort: ";     
        for(int i=0;i<size;i++)
        {
           cout<<" "<<arr[i];
        }

    return 0;
}
          







2. Optimised Bubble sort--------------------------------------------------------------------------------------------------------------------------------
=>repeatedly swap two adjacent elements if they are in wrong order
=>Sorting started from back side. First element should be sorted lastly.  
-------------------------------------------------------------------------IN JAVA----------------------------------------------------------------------- 
import java.util.Scanner;
public class bubble {
    
	public static void main(String args[])
	{
		int temp;
		int size;
		System.out.print("enter the size of the array :");
		Scanner sc=new Scanner(System.in);
		size=sc.nextInt();
		int arr[]=new int[size];
	             for(int i=0;i<size;i++)
       		     {	
			     arr[i]=sc.nextInt();
		     }
		
		for(int i=size-1;i>=1;i--)   //optimised form--- the loop will run from size-1 and decremented in every iteration
       		 {
			for(int j=0;j<i;j++)
       			 {
	                    if(arr[j]>arr[j+1])                //if found minimum then swap
			    {
	                        temp=arr[j];
				 arr[j]=arr[j+1];
				    arr[j+1]=temp;
			    }			    		    
			}
		}
		System.out.print("After Bubble sort: ");     
       			 for(int i=0;i<size;i++)
        		{
           			System.out.print(" "+arr[i]);
        		}
	}
}
	
	
	
 -------------------------------------------------------------------------IN C++-----------------------------------------------------------------------------------
	
#include <iostream>
using namespace std;

int main(){
    
 int size,temp;
          cout<<"enter the size of the array : ";
           cin>>size;
          int arr[size]; 
         for(int i=0;i<size;i++)
           {
              cin>>arr[i];
           }
        
        for(int i=size-1;i>=1;i--)
       		 {
			for(int j=0;j<i;j++)
       			 {
	                    if(arr[j]>arr[j+1])
			    {
	                        temp=arr[j];
				 arr[j]=arr[j+1];
				    arr[j+1]=temp;
			    }			    				    
			}
		}
   
    cout<<"After Bubble sort: ";     
        for(int i=0;i<size;i++)
        {
           cout<<" "<<arr[i];
        }

    return 0;
	}
          


3.insertion sort--------------------------------------------------------------------------------------------------------------------------------------------------
=>better then bubble and selection sort.
=>example-shuffling of cards.
=>in this, compares with previous element and put the element in right position	
 -----------------------------------------------------------------------c++ solution-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
int main(){   
 int size,temp,x;
          cout<<"enter the size of the array : ";
           cin>>size;
          int arr[size]; 
         for(int i=0;i<size;i++)
           {
              cin>>arr[i];
           }
        
        for(int i=1;i<=size-1;i++)
       	 {
               x=arr[i];
               temp=i;
		    while(temp>0 && arr[temp-1]>x)
       		    {
	             
			 arr[temp]=arr[temp-1];
		         temp--;
		    }			    
			 arr[temp]=x; 
	}
		
   
    cout<<"After Insertion sort: ";     
        for(int i=0;i<size;i++)
        {
           cout<<" "<<arr[i];
        }

    return 0;
}
          




4.MERGE SORT--------------------------------------------------------------------------------------------------------------------------------------------------------- 
->divide and conquer sorting algorithm
->space complexity=0(n) {due to use of extra array}
-----------------------------------------------------------------------------------c++ code-------------------------------------------------------------------------
#include <iostream>
using namespace std;
#define n 50

void conquer(int arr[],int si,int mid,int ei)
{                        //si=starting index   ei=ending index
 int l=si;
 int c=mid+1;
 int result[n];
int index=si;
while(l<=mid && c<=ei)                          //check that  if any of the two array is exhaust or not
{
    if(arr[l]>arr[c])
    {
        result[index]=arr[c];
        index++;c++;
    }
    else
    {
        result[index]=arr[l];
        index++;l++;
    }
}

if(l>mid)                                    //if we reach here it means either  of one of the array is exhausted
{
    while(c<=ei)                              //copying the remaining elements of right array
    {
        result[index]=arr[c];
        index++;c++;
    }
}
else
{
     while(l<=mid)                       //copying the remaining elements of left array
    {
        result[index]=arr[l];
        index++;l++;
    }
}
   
  for(int i=si;i<=ei;i++)           //just copying the sorted elements from temporary array to original array
  {
    arr[i]=result[i];            
 
  }  
}
   



void divide(int arr[],int si,int ei)
{
    if(ei>si)
    {
        int mid;
        mid=si+(ei-si)/2;                        //better approach for finding mid
        divide(arr,si,mid);       
        divide(arr,mid+1,ei);                    //callback hell in javascript concept used
        conquer(arr,si,mid,ei);                //callback hell in javascript concept used
    }                                          //divide and conquer works simultaneously
}


 
int main(){
    int size;
    cout<<"please enter the size of the unsorted list :";
    cin>>size;
      int arr[n],l=0,r=size-1;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Sorted list : ";
    divide(arr,l,r);
     for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

	
	
	
	



4.QUICK SORT--------------------------------------------------------------------------------------------------------------------------------------------------------- 
->divide and conquer sorting algorithm
->space complexity=0(1) {due to use of no extra array}
-----------------------------------------------------------------------------------c++ code-------------------------------------------------------------------------
	
	
	



