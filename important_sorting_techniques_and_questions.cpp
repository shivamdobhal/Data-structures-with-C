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

	
	
	
	



5.QUICK SORT--------------------------------------------------------------------------------------------------------------------------------------------------------- 
->divide and conquer sorting algorithm
->space complexity=0(1) {due to use of no extra array}
->average time complexity=o(nlogn)
	
-----------------------------------------------------------------------------------c++ code-------------------------------------------------------------------------
	
#include <iostream>
#include <math.h>
using namespace std;

void quicksort(int arr[],int ,int);     //function declaration
int partition(int arr[],int ,int);      //function declaration



void quicksort(int arr[],int l,int r)    //works recursively to sort the array  &  time complexity = o(log n) as array is dividing into 2 parts
{
	if(l<r)                       //condition satisfies till r is greater than  l
	{
  	        int par=partition(arr,l,r); 
		quicksort(arr,l,par-1);            //for left part of the pivot element
		quicksort(arr,par+1,r);            //for left part of the pivot element
	}
}


//partitioning is the root part of this algorithm in which we find that->  1.the elements which are lesser than pivot is moved to its left 
//                                                                        2.the elements which are greater than pivot is moved to its right                   
int partition(int arr[],int si,int ei)             
{
int l=si,pivot=l,r=ei;
    while(l!=r)                                                  //stops the loop when left is equals to right
    {
		while(arr[r]>=arr[pivot]  && pivot!=r)             //for right part 
        	r--;
       if(arr[r]<arr[pivot])                                   // swapping pivot with right element
        { 
          int temp;
          temp=arr[pivot];
          arr[pivot]=arr[r];
          arr[r]=temp;
        }


                while(arr[l]<arr[pivot] && pivot!=l)           //for left part
                l++;

       if(arr[l]>arr[pivot])                                  // swapping  pivot with left element
       { 
         int temp;
         temp=arr[pivot];
         arr[pivot]=arr[l];
         arr[l]=temp;
       }
  }

return pivot;
}


int main()
{
int size;
cout<<"enter the size of the array : ";
cin>>size;
int arr[size];
cout<<"enter the elements : ";     
  	for(int i=0;i<size;i++)                      //inputting array values 
	{
		cin>>arr[i];
	}

int si=0,ei=size-1;

quicksort(arr,si,ei);                             //function call
	for(int i=0;i<size;i++)                   //printing sorted array
	{
		cout<<" "<<arr[i];
	}
return 0;
}	
	
	



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QUESTION=1.what is  the case when worst time complexity of quick sort is o(n*n) i.e n square ?             [IMPORTANT]
SOLUTION->	This case arises when we select pivot at extreme ends of sorted or reversely sorted array.
	         
	                    10  20  30  40  50  60
	                     0   1   2   3   4   5
                  it gives worst time complextity when pivot = arr[0]  or pivot = arr[5]

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QUESTION-2]difference bwn quick sort and merge sort ?
SOLUTION-                        
	                               quick sort                                                               merge sort	  

                            *space complexity=n(1)                                                     *  space complexity=O(n)  
	                     no extra space required i.e,inplace algo.                                    extra space required i.e,outplace algo.
   
                            *worst time complexity=o(n*n)                                              * worst time complexity=o(nlogn)   
                            
                            *use of partitioning.                                                      *no use of partitioning & we find mid in this algo
 
                            *faster for small datasets                                                 *consistant as time complexity is equals in all cases
  
                            *unstable algo.                                                            *stable algo
 
                            *good locality of reference                                                 *poor locality of reference
 
 
