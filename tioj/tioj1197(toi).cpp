#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
//	####	####	£@¢ú¢÷¢ö¢ï~ 	####	#### 
	int m, n;
	cin >> m >> n;
	int lsn[m+1], cls[m+1], a, b;
	for ( int i=0; i<=m; i++ )
	{
		lsn[i] = 0;
		cls[i] = 0;
	}
	while ( cin >> a >> b )
	{
		lsn[a]++;
		lsn[b]++;
		if ( a < b )
			cls[b]++;
		else
			cls[a]++;
	}
	if ( *max_element(lsn, lsn+m+1) > n )
	{
		cout << 0 << endl;
		cout << *max_element(lsn, lsn+m+1) << endl;
	}
	else
	{
		long long sum=n;
		for ( int i=2; i<=m; i++ )
			sum *= (n-cls[i]);
		cout << sum << endl;
		if ( sum == 0 )
			cout << n+1 << endl;
		else
		{
			int y=(*max_element(lsn, lsn+m+1)+1)*2 - m;
			if ( y <= 0 )
				cout << 1 << endl;
			else if ( y > n )
				cout << n << endl;
			else
				cout << y << endl;
		}
	}
	return 0;
}

