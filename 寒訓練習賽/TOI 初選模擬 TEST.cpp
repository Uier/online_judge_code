#include<iostream>
using namespace std;
int main()
{
	int l, q;
	cin >> l >> q;
	int at[l];
	for ( int i=0; i<l; i++ ) 
	{
		cin >> at[i];
	}
	int a, b, d;
	long long sum=0;
	for ( int i=0; i<q; i++ )
	{
		cin >> a >> b;
		if ( a > b )
			swap(a,b);
		sum = 0;
		d=0;
		for ( int j=a-1; j<b; j++ )
		{
			if ( j == a-1)
				d++;
			else if ( at[j] != at[j-1] )
				d++;
			sum += d;
		}
		cout << sum << endl;
	}
	return 0;
}

