#include<iostream>
using namespace std;
int main()
{
	int t,a,b,r; cin >> t;
	int ans[t];
	for ( int i=0; i<t; i++ )
	{
		cin >> a >> b;
		if ( a > b )
			swap(a,b); // a «í < b 
		while ( a != 0 )
		{
			r = b % a;
			ans[i] = a;
			b = a;
			a = r;
		}
	}
	for ( int i=0; i<t; i++ )
		cout << ans[i] << endl;
	return 0;
}

