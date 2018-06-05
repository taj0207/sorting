#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int *arr, int l, int r)
{
    int pivot = arr[l];
    int i = l+1;
    int j = r-1;
    while(i<j)
    {
        while(i < r-1 && arr[i] < pivot ) ++i;
        while(j < l+1 && arr[j] > pivot) --j;
        if(i<j) swap(&arr[i],&arr[j]);
    }
    if(pivot > arr[j])
        swap(&arr[l], &arr[j]);
    return j;
}

int findkth(int arr_size, int* arr, int k,int l, int r)
{
    int result = 0;
    
    if(l<r)
    {
        result = partition(arr, l,r);
        if(result > k) result = findkth(arr_size, arr, k, l,result);
        else if(result < k) result = findkth(arr_size, arr, k, result+1,k);
    }
    return arr[result];
}

int findMedian(int arr_size, int* arr) {
    // Complete this function
    return findkth(arr_size, arr,arr_size/2,0,arr_size);
}

int main() {
    int n = 7;
    int arr[7] = {0,1,2,6,5,3,4};
    int result = findMedian(n, arr);
    printf("%d\n", result);
    return 0;
}

