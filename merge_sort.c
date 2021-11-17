#include <stdio.h>
#define max 10
int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];


void mergesort(int l, int r) {
   int mid;
   
   if( l < r) {
      mid = ( l + r) / 2;
      mergesort( l, mid);
      mergesort(mid+1, r);
      merge( l, mid, r);
   }   
}

void merge(int l, int mid, int r) {
   
int x = l,y = mid + 1, i = l;
   for(; x <= mid && y <= r; i++) {
      if(a[x] <= a[y])
         b[i] = a[x++];
      else
         b[i] = a[y++];
   }
   
   while(x <= mid)    
      b[i++] = a[x++];

   while(y <= r)   
      b[i++] = a[y++];

   for(i = l; i <= r; i++)
      a[i] = b[i];
}



int main() { 
   int i;

   printf("List before sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   mergesort(0, max);

   printf("\nList after sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}
