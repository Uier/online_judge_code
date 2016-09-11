#include <iostream>
using namespace std;
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	Fail 
	int n, x, y;
	cin >> n;
	while ( n-- ) {
		cin >> x >> y;
		if ( (x==y) || (x>0 && x%2==1 && y>-x && y<=x+1) )
			puts("YES");
		else if ( x<0 && x%2==0 && y<-x && y>=x )
			puts("YES");
		else if ( y>0 && y%2==0 && ( (x>-y && x<y)||(x<=y && x<=1-y) ) )
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

