#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_SIZE 101
using namespace std;
int A[MAX_SIZE];
int front = -1;
int rear = -1;
bool isEmpty()
{
	if(rear==-1 && front==-1)
	{
		cout<<"Empty Queue\n";
		return true;
	}
	else
	{
		cout<<"Queue not empty\n";
	}
	return false;
}
void Enqueue()
{
	int data=0;
	int add=0;
	do
	{
	cout<<"Enter the data in queue\n";
	cin>>data;
    if(isEmpty())
    {
        rear++;
        front++;
        A[rear] = data;
    }
    else
    {
    	rear++;
    	A[rear] = data;
    }
    cout<<"To enqueue enter 1\n";
    cin>>add;
    }
    while(add==1);
}
void Dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue empty\n";
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front++;
	}
}
void isFull()
{
	if(rear==MAX_SIZE-1)
	{
		cout<<"Queue Full\n";
	}
}
void front_value()
{
	cout<<"Front value is ";
	cout<<A[front];
}
int main()
{
	Enqueue();
	Dequeue();
	front_value();
	return 0;
}