#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool ex[20001]={false};
int ss[20001]={0};
int as[20001]={0};
int main()
{
	int n, q, a;
	cin >> n >> q;
	ex[10000] = true;
	for ( int i=0; i<n; i++ )
	{
		int x=0;
		cin >> a;
		for ( int j=0; j<20001; j++ )
		{
			if ( ex[j] )
			{
				ss[x++] = j+a;
				ss[x++] = j-a;
				ex[j] = false;
			}
		}
		for ( int k=0; k<x; k++ )
			ex[ss[k]] = true;
	}
	int j=0;
	for ( int i=0; i<20001; i++ )
	{
		if ( ex[i] )
			as[j++] = i-10000;
	}
	for ( int i=0; i<q; i++ )
	{
		cin >> a;
		cout << *lower_bound(as,as+j,a) << endl;
	}
	return 0;
}

