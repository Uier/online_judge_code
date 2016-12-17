#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	cin >> n;
	while ( n-- ) {
		cin >> x >> y;
		bool flag = false;
		if ( x>0 && x%2==1 && y>-x && y<=x+1 )	
			flag = true;
		else if ( x<0 && x%2==0 && y<=-x && y>=x )
			flag = true;
		else if ( y>0 && y%2==0 && (x>=-y && x<y) )
			flag = true;
		else if ( y<=0 && y%2==0 && (x>=y && x<=1-y) )
			flag = true;
		if ( flag )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

