#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#define int long long
#define maxn 50000
using namespace std;
map<int,bool> npr;
vector<int> prm;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p, y;
	cin >> p >> y;
	prm.emplace_back(2);
	for ( int i=3; i<=maxn; i+=2 )
		if ( i&1 && !npr[i] ) {
			for ( int j=i*i; j<=maxn; j+=2*i )
				npr[i] = 1;
			prm.emplace_back(i);
		}
	int ans = -1;
	if ( !(y&1) )	y--;
	for ( int i=y; i>p&&ans==-1; i-=2 ) {
		bool flag = true;
		for ( int j=0; j<prm.size()&&prm[j]<=p&&prm[j]*prm[j]<=i; ++j )
			if ( i%prm[j] == 0 )
				flag = false;
		if ( flag )	ans = i;
	}
	cout << ans << '\n';
	return 0;
}

