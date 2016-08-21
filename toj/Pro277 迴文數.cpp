#include<iostream>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	while ( n-- )
	{
		cin >> s;
		if ( s.size() == 1 )
		{
			if ( s == '9' )
				cout << 11 << endl;
			else
				cout << s-'0'+1 << endl;
		}
		for (
	}
	return 0;
}

