#include<bits/stdc++.h>
#include<stack>
int in[1010];
using namespace std;
int main()
{
	stack<int> r;
	int n;
	while ( cin >> n )
	{
		if ( n == 0 )
			break;
		while ( cin >> in[0] )
		{
			if ( in[0] == 0 )
				break;
			for ( int i=1; i<n; i++ )
				cin >> in[i];
			int j=0, k=1;
			while ( (j < n) && (k <= n) )
			{
				bool f=0;
				if ( in[j] == k )
				{
					j++;
					if ( k < n )
						k++;
					f=1;
				}
				else if ( !r.empty() )
				{
					if ( in[j] == r.top() )
					{
						r.pop();
						j++;
						f=1;
					}
				}
				if ( f == 0 )
				{
					r.push(k);
					k++;
				}
			}
			if ( r.empty() )
				cout << "Yes" << endl;
			else
			{
				cout << "No" << endl;
				while ( !r.empty() )
					r.pop();
			}
		}
		cout << endl;
	}
	return 0;
}

