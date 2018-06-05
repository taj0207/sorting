#include<iostream>
using namespace std;

void insertion_sort(int *arr, int size)
{
	for(int i=1;i<size;++i)
	{
		int tmp = arr[i];
		int j=i-1;
		while(j>=0 && tmp < arr[j])
		{
			arr[j+1] = arr[j];
			--j;	
		}
		arr[j+1] = tmp;
	}
}


int main() {
	int arr[]={3,5,10,0,7,6,8,9,22,14,8,30};
	int size = sizeof(arr)/sizeof(int);
	for(int i=0;i<size;++i) cout << arr[i] << " ";
	cout<< endl;
	insertion_sort(arr,size);
	for(int i=0;i<size;++i) cout << arr[i] << " ";
	cout << endl;
    return 0;
}

