#include <bits/stdc++.h>
#define MAX 1000
using namespace std;


int main()
{
	cout<<"Enter number of stages\n";
	int stages=0;
	cin>>stages;
	cout<<"\n";
	cout<<"Enter number of nodes in the graph --> ";
	int n=0;
	cin>>n;
	cout<<"\n";
	cout<<"Enter graph in 2*2 Matrix\n\n";
	int n1=n+1;
	int n2=n+1;
	int mat[n1][n2];
	for(int i=1;i<=n;i++)
	{
		cout<<"This is row "<<i<<"\n";
		cout<<"Enter values\n";
		for(int j=1;j<=n;j++)
		{
			cin>>mat[i][j];
		}

	}

	int min;
	int cost[n],d[n],path[n];
	cost[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		min=32767;
		for(int k=i+1;k<=n;k++)
		{
			if(mat[i][k]!=0 && mat[i][k]+cost[k]<min)
			{
				min=mat[i][k]+cost[k];
				d[i]=k;
			}
		}
		cost[i]=min;
	}
	path[1]=1;
	path[stages]=n;
	for(int l=2;l<stages;l++)
	{
		path[l]=d[path[l-1]];
	}
	cout<<"Minimum cost will be --> "<<cost[1];
	return 0;
}