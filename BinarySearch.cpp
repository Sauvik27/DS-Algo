#include <iostream>
#include <algorithm>
using namespace std;

void BinarySearch(int A[], int n, int key)
{
	int l=0;
	int h=n;
	int mid=0;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(A[mid]==key)
		{
			cout<<"Element found"<<endl;
			return;
		}
		if(A[mid]>key)
		{
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l>h)
	{
		cout<<"Element not found\n";
	}
	return;
	
}
int main()
{
	int n=0;
	int key=0;
	cout<<"enter the number of values to put under array\n";
	cin>>n;
	int A[n];
	cout<<"Enter the number of elements in array\n";
	for(int i=0;i<n;i++)
	{
        cin>>A[i];
	}
	sort(A,A+n);
	cout<<"Enter the element to find\n";
	cin>>key;
	BinarySearch(A,n,key);
	return 0;
}