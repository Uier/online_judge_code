#include<bits/stdc++.h>
using namespace std;
int main() 
{
	string s;
	while ( getline(cin, s, '%') )
	{
		long long n, all=1;
		stringstream ss(s);
		while ( ss >> n )
		{
			if ( all > 479001599 )
				all %= 479001599; 
			all *= n%479001599;
		}
		cout << all%479001599 << endl;
	} 
	return 0;
}
