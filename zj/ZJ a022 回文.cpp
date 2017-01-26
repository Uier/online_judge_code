#include<iostream>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int len=0, m=0, i=0;
		len = s.size();
		m = len/2;
		for ( ; i<m; i++ )
		{
			if ( s[i] != s[len-i-1] )
				break;
		}
		if ( i == m )
			cout << "YES" << endl;
		else
			cout << "NO" << endl; 
	}
	return 0;
}

