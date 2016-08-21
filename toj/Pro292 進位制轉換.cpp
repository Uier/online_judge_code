#include<iostream>
using namespace std;
int ans[1000];
int main()
{
	int a, b, i=0;
	cin >> a >> b; // a為目前進位置 b為目標進位置 
	if ( a == 10 )
	{
		int c;
		cin >> c;
		while( c >= b )
		{
			ans[i] = c%b;
			c /= b;
			i++;
		}
		ans[i] = c;
		for ( int j=i; j>=0; j-- )
			cout << ans[j];
		cout << endl;
	}
	else if ( b == 10 )
	{
		int tn=1, len=0, cc=0;
		long long res=0;
		string c;
		cin >> c;
		len = c.size();
		for ( int j=0; j<len; j++ )
		{
			cc = c[j] - '0';
			for ( int k=len-1-j; k>0; k-- )
				tn *= a;
			res += tn*cc;
			tn = 1;
			cc = 0;
		}
		cout << res << endl;
	}
	else
	{
		int tn=1, len=0, cc=0;
		long long res=0;
		string c;
		cin >> c;
		len = c.size();
		for ( int j=0; j<len; j++ )
		{
			cc = c[j] - '0';
			for ( int k=len-1-j; k>0; k-- )
				tn *= a;
			res += tn*cc;
			tn = 1;
			cc = 0;
		}
		while( res >= b )
		{
			ans[i] = res%b;
			res /= b;
			i++;
		}
		ans[i] = res;
		for ( int j=i; j>=0; j-- )
			cout << ans[j];
		cout << endl;
	}
	return 0;
}

