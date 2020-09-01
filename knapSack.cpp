#include <iostream>
#include <algorithm>

using namespace std;
void knapsack(int weight[], int profit[], int n_obj, int constraint)
{
	float profit_by_weight[n_obj];
	float actual_profit=0;
	float value=0;
	for(int i=0;i<n_obj;i++)
	{
		profit_by_weight[i]=profit[i]/weight[i];
	}
	for(int j=0;j<n_obj;j++)
	{
		for(int k=j+1;k<n_obj;k++)
		{
			if(profit_by_weight[j]<profit_by_weight[k])
			{
				swap(profit_by_weight[j],profit_by_weight[k]);
				swap(profit[j],profit[k]);
				swap(weight[j],weight[k]);
			}
		}
	}
	for(int l=0;l<n_obj;l++)
	{
		if(constraint!=0)
		{
			if(weight[l]>constraint)
			{
				value=profit[l]*float(constraint)/float(weight[l]);
				actual_profit=actual_profit+value;
				constraint=0;
			}
			actual_profit=actual_profit+profit[l];
			constraint=constraint-weight[l];
		}
	}
	cout<<"Maximum Profit is : "<<actual_profit;
	cout<<"\n";
}


int main()
{
	int n_obj;
	cout<<"Enter number of objects : ";
	cin>>n_obj;
	cout<<"\n";
	int weight[n_obj];
	int profit[n_obj];
	int constraint=0;
	for(int i=0;i<n_obj;i++)
	{
		cout<<"Enter weight for object "<<i+1<<" : ";
		cin>>weight[i];
		cout<<"Enter profit for object"<<i+1<<" : ";
		cin>>profit[i];
		cout<<"\n";
	}
	cout<<"Enter the max value that the bag can contain : ";
	cin>>constraint;
	cout<<"\n";
	knapsack(weight,profit,n_obj,constraint);
	return 0;
}