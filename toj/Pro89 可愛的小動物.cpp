#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int par[1000002];
int find(int x)
{
	if ( par[x] == x )
		return x;
	return par[x] = find(par[x]);
}

void union_(int x, int y)
{
	par[find(x)] = find(y);
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    string x, y, z;
    cin >> n;
    for ( int i=1; i<=n*2; i++ )
        par[i] = i;
    while ( cin >> x >> y >> z >> a >> b ) 
    {
        if ( (x[0] == 'y') && (z[0] == 'f') )      // ©w¸q 
        {
        	if ( same(a, b+n) || same(a+n, b) )
        		cout << "angry\n";
			else
			{
				union_(a, b);
				union_(a+n, b+n);
			}
		}	
        else if ( x[0] == 'y' )
        {
			if ( same(a, b) || same(a+n, b+n) )
				cout << "angry\n";
			else
			{                
	            union_(a, b+n);
	            union_(a+n, b);
	        }
	    }
        else if ( z[0] == 'f' )					   // ¸ß°Ý
        {
			if ( same(a, b) || same(a+n, b+n) )
				cout << "yeap\n";
			else
				cout << "nope\n";	
		}
		else
		{
			if ( same(a, b+n) || same(a+n, b) )
				cout << "yeap\n";
			else
				cout << "nope\n";
		}
    }
    return 0;
}
