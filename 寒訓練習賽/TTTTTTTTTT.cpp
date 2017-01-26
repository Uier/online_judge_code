#include<iostream>
#include<algorithm>
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
		sum = 0;
		if ( a > b )
			swap(a,b);
		int ans[b-a+1]={0};
		d=a-1;
		for	( int k=0; k<b-a+1; k++, d++ )
		{
			ans[k] = at[d];
		}
		sort(ans,ans+b-a+1);
		d=0;
		for ( int j=0; j<b-a+1; j++ )
		{
			if ( j == 0 )
				d++;
			else if ( ans[j] != ans[j-1] )
				d++;
			sum += d;
		}
		cout << sum << endl;
	}
	return 0;
}

