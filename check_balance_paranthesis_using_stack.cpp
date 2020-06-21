  
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
bool arepair(char top,char data)
{
	if(top=='(' && data== ')')
		return true;
	else if(top=='[' && data== ']')
		return true;
	else if(top=='{' && data== '}')
	{
		return true;
	}
	return false;
}
bool check(char *c,int n)
{
    stack<char> s;
    for(int i=0;i<n;i++)
    {
    	if(c[i]=='{' || c[i]=='[' || c[i]=='(')
    	{
    	s.push(c[i]);
        }
        else if(c[i]=='}' || c[i]==']' || c[i]==')')
        {
        	if(s.empty() || !arepair(s.top(),c[i]))
        	{
                return false;
        	}
        	else
        	{
        		s.pop();
        	}
        }
    }
        return s.empty() ? true:false;
}

int main()
{
	char c[50];
	cout<<"Enter the paranthesis\n";
	gets(c);
    if(check(c,strlen(c)))
    	cout<<"Balanced\n";
    else
    	cout<<"Not balanced\n";

    return 0;
}