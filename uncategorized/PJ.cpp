#include <iostream>
using namespace std;
struct machine {
	int u, t;
} g[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, use[10], rec[10];
	for ( int i=1; i<=10; ++i ) {
		cin >> use[i] >> rec[i];
		use[i] += rec[i];
	}
	for ( int i=1; i<=10; ++i ) {
		cin >> a >> b >> g[i].t;
		g[i].u = a+b;
	}
	long long pt = 0;
	for ( int k=0; k<3; ++k ) {
		for ( int i=1; i<=10; ++i ) {
			long long dn = pt+use[i];
			machine tmp = g[i];
			if ( pt > g[i].t+g[i].u || dn < g[i].t ) {
				pt += use[i];
			} else {
				pt = tmp.t + tmp.u + use[i];
			}
		}
	}
	cout << pt-rec[9] << '\n';
	return 0;
}

