#include <iostream>
#include <vector>
#define maxn 10000005
using namespace std;
bool npr[maxn];
vector<int> prm;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	npr[0] = npr[1] = true;
	prm.push_back(0);
	for ( int i=2; i<maxn; ++i )
		if ( !npr[i] ) {
			for ( int j=i+i; j<maxn; j+=i )
				npr[j] = true;
			prm.push_back(i);
		}
	int a, b;
	char p;
	while ( cin >> a >> p >> b ) {
		int x = lower_bound(prm.begin(),prm.end(),a)-prm.begin();
		int y = lower_bound(prm.begin(),prm.end(),b)-prm.begin();
		if ( p == '-' )
			cout << prm[x-y] << '\n';
		else if ( p == '+' )
			cout << prm[x+y] << '\n';
		else if ( p == '*' )
			cout << prm[x*y] << '\n';
		else
			cout << prm[x/y] << '\n';
	}
	return 0;
}

