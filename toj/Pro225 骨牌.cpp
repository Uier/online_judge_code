#include<iostream>
using namespace std;
int main()
{
	int n, ans=-1;
	long long max=0;
	cin >> n;
	for ( int i=0; i<n; i++ )
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if ( i )
		{
			if ( b > max )
			{
				ans = i;
				break;
			}
			if ( a+b > max )
				max = a+b;
		}
		else
			max = a+b;
	}
	if ( ans==-1 )
		cout << "hurray" << endl;
	else
		cout << n-ans << endl;
	/*
	int x=0, max=0;
	while ( !arr[x++] );
	x--;
	max = x+arr[x];
	for ( int i=x+1; i<=max; i++ )
		if ( arr[i]!=0 && arr[i]+i>max )
			max = arr[i]+i;
	int ans=0;
	for ( int i=max+1; i<100000000; i++ )
		if ( arr[i]!=0 )
			ans++;
	if ( ans == 0 )
		cout << "hurray" << endl;
	else
		cout << ans << endl;
	*/
	return 0;
}

