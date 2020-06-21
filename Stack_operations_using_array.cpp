#include <iostream>
#include <algorithm>
#define MAX_SIZE 101
using namespace std;
int a[MAX_SIZE];
int top=-1;
void push()
{
	int data;
	cout<<"\nEnter the data\n";
    cin>>data;
    if(top == MAX_SIZE-1)
    {
        cout<<"Stack Overflow\n";
        return;
    }
    top++;
    a[top]=data;
}
void pop()
{
	if(top == -1)
	{
		cout<<"Stack empty";
	}
	top--;
}
int Top()
{
    return a[top];
}
bool isEmpty()
{
	if(top==-1)
		return true;
	return false;
}
void print()
{
	int i=top;
	while(i>=0)
	{
		cout<<a[i];
		cout<<"\n";
		i--;
	}
}

int main()
{
	push();
	push();
	push();
	push();
	push();
	push();
	pop();
	cout<<"\n";
	print();
	return 0;
}