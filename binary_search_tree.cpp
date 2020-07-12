#include <iostream>
#include <algorithm>
using namespace std;

struct BSTnode
{
	int data;
	struct BSTnode* left;
	struct BSTnode* right;
};
BSTnode* insert(BSTnode* root,int data)
{
	struct BSTnode* temp=(struct BSTnode*)malloc(sizeof(BSTnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
    if(root==NULL)
    {
    	root=temp;
    }
    else if(temp->data<=root->data)
    {
    	root=insert(root->left,data);
    }
    else
    {
    	root=insert(root->right,data);
    }
    return root;
}

void search(BSTnode* root,int data)
{
    if(root==NULL)
    {
    	cout<<"No data present\n";
    }
    else if(data==root->data)
    {
    	cout<<"Data present\n";
    }
    else if(data<=root->data)
    {
    	search(root->left,data);
    }
    else if(data>=root->data)
    {
    	search(root->right,data);
    }
    else
    {
    	cout<<"Not present\n";
    }
}

int findmin(BSTnode* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return -1;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}

int findmax(BSTnode* root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return -1;
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root->data;
}

int main()
{
	struct BSTnode* root = NULL;
	int data=0;
	int searchData=0;
	int a=0;
	do
	{
         cout<<"Enter data\n";
         cin>>data;
         root = insert(root,data);
         cout<<"To enter another data press 1  --->  ";
         cin>>a;
	}while(a==1);
    cout<<"Enter a number to search\n";
    cin>>searchData;
    search(root,data);
    int min=findmin(root);
    cout<<"minimum number is ---> "<<min<<"\n";
    int max=findmax(root);
    cout<<"maximum number is ---> "<<max<<"\n";
    return 0;
}
