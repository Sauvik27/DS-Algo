#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
void reverse(char *c,int n)
{
    stack<char> s;
    for(int i=0;i<n;i++)
    {
    	s.push(c[i]);
    }
    for(int i=0;i<n;i++)
    {
    	c[i]=s.top();
    	s.pop();
    }
}

int main()
{
	char c[50];
	cout<<"enter the string\n";
	gets(c);
    reverse(c,strlen(c));
    cout<<"output: ";
    cout<<c;
}