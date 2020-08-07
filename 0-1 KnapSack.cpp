//0-1 Knapsack
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

void Knapsack(int *profit, int *weight, int n, int kg)
{
	char profitByWeight[n];
	for(int i=0;i<n;i++)
	{
        profitByWeight[i]=profit[i]/weight[i];
	}
    for(int j=0;j<n;j++)
    {
    	for(int k=j+1;k<n;k++)
    	{
    		if(profitByWeight[j]<profitByWeight[k])
    		{
    			swap(profitByWeight[j],profitByWeight[k]);
    			swap(weight[j],weight[k]);
                swap(profit[j],profit[k]);
    		}
    	}
    }
    int max=0;
    int max_profit=0;
    for(int s=0;s<n;s++)
    {
    	max=max+weight[s];
        if(max>kg)
        {
        	int y=max-kg;
        	int residue=weight[s]-y;
        	int remained=profit[s]/weight[s];
        	remained=remained*residue;
        	max_profit=max_profit+remained;
        	max=max-y;
        }
        if(max==kg)
        {
        	break;
        }
        else
        {
        	max_profit=max_profit+profit[s];
        }
    }
    cout<<"Maximum profit is --> "<<max_profit;
}

int main()
{
	cout<<"Enter max weight the bag can handle\n";
	int kg=0;
	cin>>kg;
	cout<<"Enter the number of elements to enter\n";
	int n=0;
	cin>>n;
	cout<<"------------------------------------------\n";
	cout<<"Enter profit of each object\n";
	int profit[n];
	for(int i=0;i<n;i++)
	{
		cout<<"object "<<i+1<<"--> ";
		cin>>profit[i];
	}
	cout<<"------------------------------------------\n";
	cout<<"Enter weights of each object\n";
	int weight[n];
	for(int j=0;j<n;j++)
	{
		cout<<"object "<<j+1<<"--> ";
		cin>>weight[j];
	}
    Knapsack(profit,weight,n,kg);
}