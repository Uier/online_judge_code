#include <iostream>
using namespace std;
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, m, p;
	bool color=false;
	cin >> n >> m;
	p = n*m;
	while ( p-- ) {
		char c;
		cin >> c;
		if ( c=='C' || c=='M' || c=='Y' )
			color = true;
	}
	if ( color )
		cout << "#Color\n";
	else
		cout << "#Black&White\n";
	return 0;
}

