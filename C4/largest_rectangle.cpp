#include <bits/stdc++.h>
# define ll long long  
using namespace std;
ll int largestArea(ll int hist[],int n)
{
	stack <int> index ;
	long long int top , currentArea , maxArea = 0 ;
	int i = 0 ;
	while( i < n )
	{
		if( index.empty() || hist[index.top()] <= hist[i] )
		{
			index.push(i++);
		}
		else
		{
			top = index.top() ; 
			index.pop() ;
			currentArea = hist[top] * (index.empty() ? i : i - index.top() - 1) ;
			maxArea = maxArea < currentArea ? currentArea : maxArea ;
		}
	}
	while( !index.empty()  )
	{
		top = index.top(); 		
		index.pop();
		currentArea = hist[top] * (index.empty() ? i : i - index.top() - 1) ;
		maxArea = maxArea < currentArea ? currentArea : maxArea ;
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