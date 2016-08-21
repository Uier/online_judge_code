#include <iostream>
using namespace std;
int a[26];
int main()
{
	string l, s;
	getline(cin,l);
	cin >> s;
	for ( int i=0; i<s.size(); i++ )
		a[s[i]-65]++;
	for ( int i=0; i<l.size(); i++ )
	{
		if ( l[i] != ' ' )
		{
			if ( a[l[i]-65]==0 )
				break;
			else
				a[l[i]-65]--;
			cout << l[i];			
		}
		else
			cout << l[i];
	}
	cout << endl;
	return 0;
}

