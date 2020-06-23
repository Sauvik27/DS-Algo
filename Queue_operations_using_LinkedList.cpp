#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void Enqueue()
{
	struct node* temp1=head;
	int data=0;
	int add;
	do
	{
	struct node* temp=(struct node*)malloc(sizeof(node));
	cout<<"Enter data\n";
	cin>>data;
    temp->data=data;
    temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		temp1=temp;
	}
	else
	{
        temp->next=temp1;
        head=temp;
        temp1=temp;
	}
	cout<<"To enter a new value type 1\n";
	cin>>add;
    }
	while(add==1);
}
void Dequeue()
{
	struct node* temp=head;
	struct node* temp1=NULL;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
    temp1=temp->next;
    temp->next=NULL;
    free(temp1);
}
void display()
{
	struct node* temp1=head;
	while(temp1!=NULL)
	{
		cout<<temp1->data;
        cout<<"---";
		temp1=temp1->next;
	}
	cout<<"\n";
}
void isEmpty()
{
	if(head==NULL)
	{
		cout<<"queue empty\n";
	}
	else
	{
		cout<<"queue not empty\n";
	}
}
int main()
{
	Enqueue();
	Dequeue();
	display();
	isEmpty();
	return 0;
}