#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string a, b;
	cin >> a >> b;
	int ans=0;
	bool y=true;
	if ( a.size() > b.size() )
	{
		for ( int i=0; i<b.size(); i++ )
		{
			for ( int j=0; j<=i&&y; j++ )
				if ( a[j] != b[b.size()-1-i+j] )
					y = false;
			if ( y )
				ans = i+1;
			else
				y = true;
		}
	}
	else
	{
		for ( int i=0; i<a.size(); i++ )
		{
			for ( int j=0; j<=i&&y; j++ )
				if ( a[j] != b[b.size()-1-i+j] )
					y = false;
			if ( y )
				ans = i+1;
			else
				y = true;
		}
	}
	cout << ans << endl;
	return 0;
}