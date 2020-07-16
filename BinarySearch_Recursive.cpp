#include <iostream>
#include <algorithm>
using namespace std;

void BinarySearch_recursive(int A[], int n, int key, int l)
{
	if(l==n)
	{
		if(A[l]==key)
		{
			cout<<"Element found\n";
			return;
		}
		else
		{
			cout<<"Element not found\n";
			return;
		}
	}
	else
	{
	int mid=(l+n)/2;
	if(A[mid]==key)
	{
		cout<<"Element found\n";
		return;
	}
	if(key<A[mid])
	{
	    BinarySearch_recursive(A,mid-1,key,l);
    }
    else
    {
    	BinarySearch_recursive(A,n,key,mid+1);
    }
    }
}
int main()
{
	int l=0;
	int n=0;
	int another=0;
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
    do
    {
    	cout<<"Enter the element to find\n";
	    cin>>key;
	    BinarySearch_recursive(A,n,key,l);
	    cout<<"To find another element press 1";
	    cin>>another;
    }while(another==1);
	return 0;
}