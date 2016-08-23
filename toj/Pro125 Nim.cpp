#include <iostream>
using namespace std;
int b[10000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p, c, x=0;
	cin >> n >> p >> c;
	while ( n-- ) {
		for ( int i=0; i<p; i++ )
		{
			int a;
			cin >> a;
			b[i]+=a;
		}
	}
	for ( int i=0; i<p; i++ )
		x ^= b[i];
	if ( x!=0&&c==0 || x==0&&c!=0 )
		cout << "Holly Win!\n";
	else
		cout << "Ivy Win!\n";	
	return 0;
}

