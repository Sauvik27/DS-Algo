#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void insert()
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
        temp1->next=temp;
        temp1=temp1->next;
	}
	cout<<"To enter a new value type 1\n";
	cin>>add;
    }
	while(add==1);
}
void reverse()
{
	stack<struct node*> s;
	//push
	struct node* temp=head;
	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->next;
	}
	//pop
	temp = s.top();
	head=temp;
	s.pop();
	while(!s.empty())
	{
		temp->next=s.top();
		s.pop();
		temp=temp->next;
	}
	temp->next=NULL;
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

int main()
{
    insert();
    display();
    reverse();
    display();
    return 0;
}