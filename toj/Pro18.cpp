#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	while ( getline(cin,s) )
	{
		int len=s.size();
		char a[len+5];
		int b=0, c=s.size();
		for ( int i=0; i<len; i++ )
		{
			if ( s[i] >= 65 && s[i] <= 90 )
				a[b++] = s[i];
			else if ( s[i] >= 97 && s[i] <= 122)
				a[b++] = s[i]-32;
			else
				c--;
		}
		bool yn=true;
		for ( int i=0; i<c/2&&yn; i++ )
			if ( a[i] != a[c-1-i] )
				yn = false;
		if ( yn )
			cout << "SETUP! " << s << endl;
		else
			cout << s << endl;
	}
	return 0;
}