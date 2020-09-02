#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void job_sequencing(int profit[],int deadline[],int n)
{
	int max_deadline=0;
	int profit_found=0;
	int count=0;
	int temp=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(profit[i]<profit[j])
			{
				swap(profit[i],profit[j]);
				swap(deadline[i],deadline[j]);
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		if(max_deadline<deadline[k])
		{
			max_deadline=deadline[k];
		}
	}
	int profit_place[max_deadline] = {};
	for(int l=0;l<max_deadline;l++)
	{
		for(int n=0;n<deadline[l]-1;n++)
		{
			if(profit_place[n]==0)
			{
				count=1;
				temp++;
			}
		}
		if(deadline[l]<=max_deadline && profit_place[deadline[l]-1] == 0)
		{
			profit_place[deadline[l]-1]=profit[l];
		}
		if(deadline[l]<=max_deadline && count==1)
		{
			profit_place[temp]=profit[l];
		}
	}
	for(int m=0;m<max_deadline;m++)
	{
		profit_found = profit_found + profit_place[m];
	}
	cout<<"Maximum profit is : "<<profit_found<<endl;
}

int main()
{
	cout<<"Enter the number of jobs to be done : ";
	int n=0;
	cin>>n;
	cout<<"\n";
	int profit[n];
	int deadline[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter profit for job "<<i+1<<" : ";
		cin>>profit[i];
		cout<<"Enter deadline for job "<<i+1<<" : ";
		cin>>deadline[i];
		cout<<"\n";
	}
	job_sequencing(profit,deadline,n);
}