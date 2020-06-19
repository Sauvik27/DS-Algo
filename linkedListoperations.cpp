#include <iostream>
#include <algorithm>

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
void insertAtBegining()
{
	int data=0;
	struct node* temp=(struct node*)malloc(sizeof(node));
	struct node* temp1=head;
	cout<<"insert data at begining\n";
	cin>>data;
    temp->data=data;
    head=temp;
    temp->next=temp1;
}
void insert_at_nth_position()
{
	int data=0;
	struct node* temp=(struct node*)malloc(sizeof(node));
	struct node* temp1=head;
	struct node* temp2=NULL;
	cout<<"insert data at nth position\n";
	cin>>data;
    temp->data=data;
    int n;
    cout<<"enter the position after which data is to be inserted\n";
    cin>>n;
    while(n!=1)
    {
    	temp1=temp1->next;
    	n--;
    }
    temp2=temp1->next;
    temp1->next=temp;
    temp->next=temp2;
}
void delete_at_nth_position()//edge case=this function does not work on begining and end, i haven't checked.
{
	int n;
    cout<<"enter the position at which data is to be deleted\n";
    cin>>n;
    struct node* temp1=head;
    struct node* temp2=NULL;
    int i=1;
    while(i<n-1)
    {
    	temp1=temp1->next;
    	i++;
    }
    if(n!=1)
    {
        temp2=temp1->next;
        if(temp2->next!=NULL)
        {
            temp1->next=temp2->next;
        }
        else
        {
    	    temp1->next=NULL;
        }
        free(temp2);
    }
    else
    {
        head=temp1->next;
        temp1->next=NULL;
        free(temp1);
    }
    
}
void reverse()//not using recursion
{
	struct node* curr=head;
    struct node* prev=NULL;
    struct node* next1=NULL;
    while(curr!=NULL)
    {
    	next1=curr->next;
    	curr->next=prev;
    	prev=curr;
    	curr=next1;
    }
    head=prev;
}
void display_using_recursion(struct node* temp)
{
	cout<<temp->data;
	cout<<"---";
	if(temp->next==NULL)
	{
		return;
	}
	display_using_recursion(temp->next);
}
void reverseprint_using_recursion(struct node* temp)
{
	if(temp==NULL)
	{
		return;
	}
	reverseprint_using_recursion(temp->next);
	cout<<temp->data;
	cout<<"---";
}
void reverse_using_recursion(struct node* curr)
{
	if(curr->next==NULL)
	{
		head=curr;
		return;
	}
	reverse_using_recursion(curr->next);
	struct node* temp = curr->next;
	temp->next = curr;
	curr->next=NULL;
}
int main()
{
	insert();
	display();
	insertAtBegining();
	display();
	insert_at_nth_position();
	display();
	delete_at_nth_position();
	display();
	reverse();
	display();
	display_using_recursion(head);
	reverseprint_using_recursion(head);
	reverse_using_recursion(head);
	display();
    return 0;
}