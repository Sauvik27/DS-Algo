#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
struct node* top=NULL;

void insert()//here insertion is done at the begining
{
	int add=0;
	do
	{
	struct node* temp=(struct node*)malloc(sizeof(node));
	cout<<"enter data in the node\n";
	cin>>temp->data;
	if(top == NULL)
	{
		top=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
    cout<<"to push more enter 1\n";
    cin>>add;
    }
	while(add==1);
}
void pop()
{
	struct node* temp=top;
	top = temp->next;
	free(temp);
}
void isEmpty()
{
	if(top == NULL)
	{
		cout<<"Empty STACK\n";
	}
	else
	{
		cout<<"STACK not empty\n";
	}
}
void print()
{
	struct node* temp=top;
	while(temp!=0)
	{
		 cout<<temp->data;
		 cout<<"\n";
		 temp=temp->next;
	}
}

int main()
{
	insert();
	pop();
	isEmpty();
	print();
}