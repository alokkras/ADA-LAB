//johnson-Trotter full permutation algorithm Input: a random number n Output: display the full permutation of n.
 // Due to the limited permutation, the maximum first limit is 7 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
 typedef struct element 
{
	int value;
	int state;
}element;

element e1;

#define MAXN 100

element arr[MAXN];
int counter=0;

void swap(int i,int j){
	element t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
} 

void JST(int n,int maxIndex) {
	
	printf("The %dth:",++counter);
	for(int i=1; i<=n; i++) {
		printf("%d",arr[i]);
	}
	printf("\n");

	int maxIndexValue=arr[maxIndex].value;
	swap(maxIndex,maxIndex+arr[maxIndex].state);
	
	for(int i=1;i<=n;i++){
		if(arr[i].value>maxIndexValue){
			arr[i].state=(arr[i].state==1)?-1:1;
		}
	}

	
	int isCanMove= 0; 
	int flagMax; 
	int valueMax=-1; 
	for(int i=1; i<=n; i++) {
		if(arr[i].state==1) {
			if(arr[i].value>arr[i+1].value&&arr[i].value>=valueMax) {
				flagMax=i;
				valueMax=arr[i].value;
				isCanMove=1;
			}
		}
		
		if(arr[i].state==-1) {
			if(arr[i].value>arr[i-1].value&&arr[i].value>=valueMax) {
				flagMax=i;
				valueMax=arr[i].value;
				isCanMove= 1;
			}
		}
	}
	
	if(isCanMove) JST(n,flagMax);
	else {
		printf("The %dth:",++counter);
		for(int i=1; i<=n; i++) {
			printf("%d",arr[i]);
		}
	}
	return ;
}
int main() {
	
	 double total_time;
   clock_t start, end;
	
	srand(time(NULL));
	
	int n = rand() % 5+2;
	arr[0].value=9999; 
	arr[n+1].value=9999;  
	for(int i=1; i<=n; i++) {
		arr[i].value=i;
		arr[i].state=-1;
	}
	 start = clock();
	JST(n,n);
	 end = clock();
	printf("\n The number of %d is arranged in a total of %d",n,counter);
	
	total_time = ((double) (end - start)) / CLK_TCK;
	
	printf("\nTime taken is: %f", total_time);
   return 0;
}
