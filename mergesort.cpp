#include<iostream>
using namespace std;

void merge(int *arr, int l, int r)
{
	int *tmp = new int[r-l+1];
	int i = l;
	int j = l+(r-l+1)/2;
	int idx = 0;
    while(i<l+(r-l+1)/2 && j <=r)
	{
		if(arr[i] <= arr[j]) 
			tmp[idx++]=arr[i++];
		else
			tmp[idx++] = arr[j++];
	}

	while(i<l+(r-l+1)/2)
	{
		tmp[idx++] = arr[i++];		
	}	
		
	for(i=0;i<idx;++i)
	{
		arr[l+i] = tmp[i];
	}
    return;
}

void mergesort(int *arr, int l, int r)
{
	if(l>=r) return;
    mergesort(arr,l,l+(r-l+1)/2-1);
    mergesort(arr,l+(r-l+1)/2,r);
    merge(arr,l,r);
}

int main() {
	int arr[]={3,5,10,0,7,6,8,9,22,14,8,30};
	int size = sizeof(arr)/sizeof(int);
	for(int i=0;i<size;++i) cout << arr[i] << " ";
cout<< endl;
	mergesort(arr,0,size-1);
	for(int i=0;i<size;++i) cout << arr[i] << " ";
	cout << endl;
    return 0;
}

