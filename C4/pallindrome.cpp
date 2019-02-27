#include <bits/stdc++.h>
using namespace std;
string isPallindrome(string str)
{
	stack<char>stck;
	int i = 0 ;
	while( str[i] != 'X' )
	{
		stck.push(str[i]); 
		i++ ;
	}
	i++;
	while(str[i])
	{
		if( stck.empty() || str[i] != stck.top() )
		{
			return "Not Pallindrome";
		}
		else
		{
			stck.pop();
		}
		i++;
	}			
	return stck.empty() ? "Pallindrome" : "Not Pallindrome" ;
}
int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		string str;
		cin >> str;
		cout << isPallindrome(str) << endl ;
	}
	return 0 ;
}