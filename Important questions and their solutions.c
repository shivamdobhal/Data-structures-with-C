Q1. Write a the C program to create an array by inserting  N elements in it then find second non repeating element from the array.

Solution==
 #include <stdio.h>
#include <stdlib.h>

int sec_non_rep(int arr[],int n)
{
          int i=0,j=0,x=0;
          int count=0;

       for(i=0 ; i<n ;  i++)
      {
         count=0;
                 for(j=0 ; j<n ;  j++)
                {
                      if(arr[i]==arr[j])
                      {
                        count=count++;
                       }
               }
        if(count==1)
       {
            x++;      //for finding 2nd non rep value
       }
        if(x==2)        //for finding 2nd non rep value
       {
          printf("second non repeating value is %d",arr[i]);
       }
    }
    }
int main()
{
int i=0,n=8;
int aray[n];
printf("shivamdobhal_20011851_C\n");
printf("enter the elements of the array\n");
for(i=0;i<n;i++)
{
    scanf("%d",&array[i]);
}
sec_non_rep(array,n);
return 0;
}



Q2. Write a the C program to create an array by inserting  N elements in it then find third repeating element from the array.

#include <stdio.h>
#include <stdlib.h>

int third_repeating(int arr[],int n)
{
    int i=0,j=0,x=0;
    int count=0;

    for(i=0 ; i<n ;  i++)
  {  count=0;
      for(j=0 ; j<n ;  j++)
    {
        if(arr[i]==arr[j])
        {
            count=count +1;
        }
    }
    if(count==2)
    {
        x++;
    }
    if(x==3)              //for third repeating value
    {
        printf("Third repeating  value is %d",arr[i]);
        break;                     //for breaking the loop
    }
    }
  
    }


int main()
{
int i=0,n;
printf("enter the size of the array :");
scanf("%d",&n);
int array[n];
printf("shivamdobhal_20011851_C\n");
printf("enter the elements of the array\n");
for(i=0;i<n;i++)
{
    scanf("%d",&array[i]);
}
third_repeating(array,n);
return 0;
}


