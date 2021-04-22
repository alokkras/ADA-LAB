#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubblesort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\n Sorted array is as follows: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int rec_linear(int arr[], int l, int r, int x) {
    if (r < l) 
    return -1;
    if(arr[l] == x)
    return l;
    if(arr[r] == x)
    return r;
    return rec_linear(arr, l+1, r-1, x);
}

int rec_binary(int arr[], int l, int r, int x) {
    if(r >= l) {
        int mid = (l+r)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return rec_binary(arr, l, mid-1, x);
        if (arr[mid] < x)
            return rec_binary(arr, mid+1, r, x);
    }
    return -1;
}

int main() {
    int arr[50],n, x, ele, res;
    clock_t start, end;
    printf("\n Enter size of the array: ");
    scanf("%d", &n);
    printf("\n Enter elements of the array: ");
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printf("\n Elements of the array are: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n Enter the element to be searched for: ");
    scanf("%d", &ele);
    do {
        printf("\n 1. Linear Search");
        printf("\n 2. Binary Search");
        printf("\n 3.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &x);
        switch(x) {
            case 1: 
                    start = clock();
                    res = rec_linear(arr, 0, n-1, ele);
                    end = clock();
                    if(res == -1) {
                        printf("\n Element not found...");
                    }
                    else {
                        printf("\n Element found at index %d", res);
                    }
                    printf("\n Time taken = %lf", (double)(end-start)/CLOCKS_PER_SEC);
            break;
            case 2: start = clock();
                    bubblesort(arr, n);
                    res = rec_binary(arr, 0, n-1, ele);
                    end = clock();
                    if(res == -1) {
                        printf("\n Element not found...");
                    }
                    else {
                        printf("\n Element found at index %d", res);
                    }
                    printf("\n Time taken = %lf", (double)(end-start)/CLOCKS_PER_SEC);
            break;
            case 3: exit(0);
            break;
            default: printf("\n Inavlid Option");
        }
    } while (x >= 1 && x <= 3);
    return 0;
}
