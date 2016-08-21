#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while ( getline(cin, s) )
	{
		for ( int i=0; i<s.size(); i++ )
		{
			if (s[i] == '/')
			{
				for ( int j=i; s[j]!=' '&&j>=0; j-- )
					 s[j] = ' ';
				for ( int j=i+1; s[j]!=' '&&j<s.size(); j++ )
					s[j] = ' ';
			}
		}
		stringstream ss(s);
		long long n, all=0;
		while ( ss >> n )
		{
			all += n;
		}
		cout << all%1000000007 << endl;
	}
	return 0;
}

