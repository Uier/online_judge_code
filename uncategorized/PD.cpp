#include <iostream>
#include <vector>
using namespace std;
vector<int> V;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, x;
	string s;
	cin >> n >> q;
	for ( int i=0; i<q; ++i ) {
		cin >> s;
		if ( s[0] == 'u' ) {
			cin >> x;
			while ( x-- )	V.pop_back();
		} else {
			int tmp = 0, j = 0;
			bool neg = false;
			if ( s[0] == '-' ) {
				neg = true;
				j++;
			}
			for ( ; j<s.size(); ++j ) {
				tmp *= 10;
				tmp += s[j]-'0';
			}
			if ( neg )	tmp *= -1;
			V.emplace_back(tmp);
		}
	}
	int sum = 0;
	for ( int i : V )	sum += i;
	cout << ((sum%n)+n)%n << '\n';
	return 0;
}

