#include <bits/stdc++.h>
using namespace std;

stack<int>stck;
stack<int>minstack;

int getMinStack()
{
	return minstack.top();
}
int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		int n , val ;
		cin >> n ;
		for ( int i = 0 ; i < n ; i++)
		{
			cin >> val ;
			if ( minstack.empty() || minstack.top() >= val )
			{
				minstack.push(val);
			}
			stck.push(val);
		}
		cout << getMinStack() << " " << minstack.size() << endl ;
		while(!minstack.empty())
			minstack.pop();
		while(!stck.empty())
			stck.pop();
	}
	return 0 ;
}