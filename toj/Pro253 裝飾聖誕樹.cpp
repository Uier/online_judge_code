#include<iostream>
#include<algorithm>
using namespace std;
int qs[110];
int main()
{
	int n, q, x=0, y=0;
	cin >> n >> q;
	n -= 2000;
	for ( int i=0; i<q; i++ )
		cin >> qs[i];
	sort(qs,qs+q);
	for ( int i=0; i<q-1; i++ )
	{
		if ( qs[i] == qs[i+1] )
			qs[i]=qs[i+1]=-1;
	} 
	for ( int i=0; i<n; i++ )
	{
		for ( int j=0; j<n-1-i; j++ )
			cout << ' ';
		while ( qs[x] == -1 )
			x++;
		if ( i+1 == qs[x] )
		{
			for ( int a=0; a<i+1; a++ )
			{
				cout << char(65+a);
				y = 65 + a;
			}
			for ( int b=0; b<i; b++ )
				cout << char(y-1-b);
			x++;
		}
		else
		{
			for ( int k=0; k<i*2+1; k++ )
				cout << '*';
		}
		cout << endl;
	}
	for ( int i=0; i<n-1; i++ )
	{
		cout << ' ';
		for ( int j=0; j<n*2-3; j++ )
			cout << '^';
		cout << endl;
	}
	return 0;
}

