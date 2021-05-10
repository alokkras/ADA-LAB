#include<stdio.h>
#include<time.h>
int main()
{
   
   int i, j, size, temp, data[25];
   double total_time;
   clock_t start, end;
   
   printf("Enter The Size of the Array:\n");
   scanf("%d",&size);

   printf("Enter %d elements:\n", size);
   for(i=0;i<size;i++)
      scanf("%d",&data[i]);

   start = clock();
   for(i=1;i<size;i++){
      temp=data[i];
      j=i-1;
      while((temp<data[j])&&(j>=0)){
         data[j+1]=data[j];
         j=j-1;
      }
      data[j+1]=temp;
   }

   printf("Order of Sorted elements: ");
   for(i=0;i<size;i++)
      printf(" %d",data[i]);
      
   end = clock();
	total_time = ((double) (end - start)) / CLK_TCK;
	
	printf("\nTime taken is: %f", total_time);
   return 0;
}
