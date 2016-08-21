#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while ( getline(cin, s) )
	{
		long long tmp[100], r=0;
		long long n, all=1;
		for ( int i=0; i<100; i++ )
			tmp[i] = 0;
		for ( int i=0; i<s.size(); i++ )
		{
			long long x=0, y=0;
			if (s[i] == '/')
			{
				for ( int j=i-1, k=0; s[j]!=' '&&j>=0; j--, k++ )
				{
					int kk=k;
					int a=1;
					while ( kk-- )
					{
						a *= 10;
					}
					x += a*(s[j]-'0');
					s[j] = ' ';
				}
				int p=i;
				while ( (s[p] != ' ')&&p<s.size() )
				{
					p++;
				}
				if ( p == s.size()-1 )
					p++;
				for ( int j=p-1, k=0; j>i; j--, k++ )
				{
					int kk=k;
					int a=1;
					while ( kk-- )
					{
						a *= 10;
					}
					y += a*(s[j]-'0');
					s[j] = ' ';
				}
				tmp[r++] = y;
				all *= x;
				s[i] = ' ';
			}
		}
		stringstream ss(s);
		while ( ss >> n )
		{
			all *= n;
		}
		long long t=1;
		for ( int i=0; i<r; i++ )
		{
			if ( all%tmp[i] == 0 )
				all /= tmp[i];
			else
				t *= tmp[i];
		}
		while ( __gcd(all,t) != 1 )
		{
			long long h=__gcd(all,t);
			all /= h;
			t /= h;
		}
		if ( t == 1 )
			cout << all << endl;
		else
			cout << all << '/' << t << endl;
	}
	return 0;
}

