#include <bits/stdc++.h>
using namespace std ;
int postfix_evaluator( string str)
{
	stack<int>s;
	for ( auto c : str  )
	{
		int n1 , n2 ;
		if ( c >= '0' && c <= '9' )
		{
			s.push(c-'0');
		}
		else
		{
			if ( s.size() >= 2 )
			{
				n1 = s.top() ; s.pop() ;
				n2 = s.top() ; s.pop() ;
				switch(c)
				{
					case '+' : s.push(n2+n1);
								break;
					case '-' : s.push(n2-n1);
								break;
					case '/' : s.push(n2/n1);
								break;
					case '*' : s.push(n2*n1);
								break;
				}
			}
		}
	}
	int tmp = s.top();
	s.pop();
	return tmp ;

}
int main()
{
	int t ;
	cin >> t;
	while(t--)
	{
		string str ;
		cin >> str ;
		cout << postfix_evaluator(str) << endl ;
	}
	return 0 ;
}