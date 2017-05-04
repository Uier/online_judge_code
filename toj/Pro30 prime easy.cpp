#include <iostream>
#define mn 1000001
using namespace std;
int prm[mn];
bool npr[mn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c = 0;
	prm[1] = c;
	for ( int i=2; i<mn; i++ )
		if ( !npr[i] ) {
			for ( int j=i+i; j<mn; j+=i )
				npr[j] = true;
			prm[i] = ++c;
		}
		else
			prm[i] = c;
	int n;
	while ( cin >> n )
		cout << prm[n] << '\n';
	return 0;
}

