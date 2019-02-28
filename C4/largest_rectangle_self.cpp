#include <bits/stdc++.h>
# define ll long long
using namespace std;
ll int largestArea(ll int hist[],int n)
{
	stack <int> index ;
	long long int currentArea , maxArea = -1 ;
	int left , top ;
	for ( int i = 0 ; i <= n ; i++)
	{
		while( !index.empty() && (i == n || hist[index.top()] > hist[i]) )
		{
			if ( index.size() > 1 )
			{
				top = index.top();
				index.pop();
				left = index.top();
			}
			else
			{
				left = -1 ;
				top = index.top() ;
				index.pop();
			}
			currentArea = hist[top] * ( i - left - 1) ;
			maxArea = maxArea < currentArea ? currentArea : maxArea ;
		}
		if( i < n )
		{
			index.push(i);
		}
	}
	return maxArea ;
}
int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		int n ;
		cin >> n ;
		ll int arr[n];
		for( int  i = 0 ; i < n ; i++ )
			cin >> arr[i];
		cout << largestArea(arr,n) << endl ;
	}
	return 0 ;
}
