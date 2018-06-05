#define DEBUG 1 
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int front, int end){
    int pivot = arr[front];
    int i = front+1;
    int j = end-1;
    while(i<j)
    {
        while(i<end-1 && pivot > arr[i]) ++i;
        while(j >front+1  && pivot < arr[j]) --j;
        if(i<j)
        swap(&arr[i], &arr[j]);    
    }
    if(pivot > arr[j])
    swap(&arr[j], &arr[front]);
    return j;
}
#if DEBUG
void PrintArray(int *arr,int size);
#else
#define PrintArray(arr,size)
#endif
void quicksort(int *arr, int front, int end){
    if (front+1 < end) {
        int pivot = partition(arr, front, end);
        PrintArray(arr,5);
        quicksort(arr, front, pivot );
        quicksort(arr, pivot + 1, end);
    }
}

#if DEBUG 
void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
#endif
int main() {

    int n = 5;
    int arr[] = { 4, 5, 3, 7, 2};
    //std::cout << "original:\n";
    PrintArray(arr, n);

    quicksort(arr, 0, n);

    //std::cout << "sorted:\n";
    PrintArray(arr, n);
    return 0;
}
