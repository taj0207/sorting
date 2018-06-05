#include<iostream>
using namespace std;

int binarysearch(int *arr, int target, int size)
{
 	int l=0, r=size-1;
	while(l<r)
	{
		int mid = l+(r-l+1)/2;
		if(arr[mid] < target) 
			l =  mid;
		else if(arr[mid]>target)
			r = mid-1;
		else
			return mid;
	}
			
	return target == arr[l]? l:-1;
}

int main() {
	int arr[]={3,5,10,11,17,61,81,91,220,1400};
	int size = sizeof(arr)/sizeof(int);
	cout << binarysearch(arr,11,size)<<endl;
	for(int i=0;i<size;++i) cout << arr[i] << " ";
	cout << endl;
    return 0;
}

