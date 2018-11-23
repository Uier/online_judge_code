#include <iostream>
#include <vector>
#define maxn 100005
#define int long long
using namespace std;
bool npr[maxn];
vector<int> prm;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for ( int i=2; i<maxn; ++i ) {
		if ( !npr[i] ) {
			for ( int j=i*i; j<maxn; j+=i ) {
				npr[j] = true;
			}
			if ( i != 2 ) prm.emplace_back(i);
		}
	}
	long long n, ans = 0, x = -1;
	cin >> n;
	if ( n&1 ) {
		for ( int i : prm ) {
			if ( n%i == 0 ) {
				x = i;
				break;
			}
		}
		if ( x == -1 )	cout << 1 << '\n';
		else {
			if ( (n-x)&1 ) {
				cout << n/x << '\n';
			} else {
				cout << (n-x)/2+1 << '\n';
			}
		}
	} else {
		cout << n/2 << '\n';
	}
	return 0;
}

