#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x, fst=0, sec=0;
	cin >> n >> k >> fst >> sec;
	if ( fst < sec )
		swap(fst,sec);
	for ( int i=2; i<n; i++ ) {
		cin >> x;
		if ( x > fst ) {
			sec = fst;
			fst = x;
		}
		else if ( x > sec )
			sec = x;
	}
	cout << sec << '\n';
	return 0;
}

