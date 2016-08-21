#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while ( getline(cin, s) )
	{
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

