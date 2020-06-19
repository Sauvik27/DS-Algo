#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head=NULL;
void insert()
{
	struct node* temp1=NULL;
	int data=0;
	int add=0;
	do
	{
	    struct node* temp=(struct node*)malloc(sizeof(node));
        cout<<"Enter data in node\n";
        cin>>data;
        temp->data=data;
        if(head==NULL)
        {
    	    head=temp;
    	    temp->prev=NULL;
    	    temp->next=NULL;
    	    temp1=temp;
        }
        else
        {
            temp1->next=temp;
            temp->prev=temp1;
            temp->next=NULL;
            temp1=temp;
        }
        cout<<"To add another data press 1\n";
        cin>>add;
    }while(add==1);
}
void display_forward()
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
void display_reverse()
{
	struct node* temp1=head;
	while(temp1->next!=NULL)
	{
        temp1=temp1->next;
	}
	while(temp1!=NULL)
	{
		cout<<temp1->data;
		cout<<"---";
		temp1=temp1->prev;
	}
	cout<<"\n";
}
void delete_at_nth()
{
	struct node* temp1=head;
	struct node* temp=NULL;
	int n=0;
	cout<<"Enter the position for which the data is to be deleted\n";
	cin>>n;
	int i=0;
	while(i<n-1)
	{
		temp1=temp1->next;
		i++;
	}
    temp=temp1->next;
    temp->prev=temp1->prev;
    temp1->prev->next=temp;
    free(temp1);
}
void insertAtBegining()
{
	struct node* temp=(struct node*)malloc(sizeof(node));
	struct node* temp1=head;
	cout<<"insert data at begining\n";
	cin>>temp->data;
    temp1->prev=temp;
    temp->next=temp1;
    temp->prev=NULL;
    head=temp;
}
void insert_at_nth_position()
{
	int i=0;
	struct node* temp=(struct node*)malloc(sizeof(node));
	struct node* temp1=head;
	int n;
    cout<<"enter the position after which data is to be inserted\n";
    cin>>n;
	cout<<"insert data at nth position\n";
	cin>>temp->data;
    while(i<n-1)
    {
        temp1=temp1->next;
        i++;
    }
    temp1->next->prev=temp;
    temp->next=temp1->next;
    temp1->next=temp;
    temp->prev=temp1;
}

int main()
{
	insert();
	display_forward();
	display_reverse();
	delete_at_nth();
	display_forward();
	insertAtBegining();
	display_forward();
    insert_at_nth_position();
    display_forward();
}