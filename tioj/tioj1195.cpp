#include<iostream>
using namespace std;
int main()
{
	int n;
	long long sum=0;
	cin >> n;
	while ( n-- )
	{
		string s;
		cin >> s;
		char a, b, c, d;
		a = s[2];	b = s[3];
		c = s[4];	d = s[5];
		if ( a == b && c == d && b == c )
			sum += 2000;
		else if ( a == b || c == d )
		{
			if ( b == c )
				sum += 1000;
			else
				sum += 1500;
		}
	}
	cout << sum << endl;
	return 0;
}

