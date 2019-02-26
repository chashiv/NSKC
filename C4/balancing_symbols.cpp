#include <bits/stdc++.h>
using namespace std ;
bool isBalanced( string str )
{
	stack<char>s;
	char ch ;
	for ( auto c : str )
	{
		switch(c)
		{
			case '[' :
			case '{' :
			case '(' : s.push(c);			
						break;
			case ']' : if( s.empty() || s.top() != '[')
						{
							return false;
						} 
						s.pop();
						break;
			case '}' : if( s.empty() || s.top() != '{')
						{
							return false;
						} 
						s.pop();
						break;
			case ')' : if( s.empty() || s.top() != '(')
						{
							return false;
						} 
						s.pop();
						break;
		}
	} 
	return s.empty();
}
int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		string str ;
		cin >> str ;
		if( isBalanced(str) )
		{
			cout << "balanced" << endl ;
		}
		else
		{
			cout << "not balanced" << endl ;		
		}
	}
	return 0;
}

