#include <iostream>
using namespace std;
int cnt[105], arr[105], vis[105], spe[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s = 0, t = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for ( int i=1; i<=100; ++i ) {
		if ( cnt[i] == 2 )	spe[i] = 1;
		else if ( cnt[i] == 1 )	s++;
		else if ( cnt[i] ) {
			spe[i] = 2;
			t++;
		}
	}
	if ( s&1 && t == 0 )	return cout << "NO\n", 0;
	else {
		if ( s&1 ) {
			for ( int i=1; i<=100; ++i )
				if ( spe[i] == 2 ) {
					spe[i] = 0;
					break;
				}
		}
		cout << "YES\n";
		bool A = true;
		for ( int i=0; i<n; ++i ) {
			int x = arr[i];
			if ( spe[x] ) {
				cout << 'B';
			} else {
				if ( vis[x] == 0 ) {
					if ( A ) {
						vis[x] = 1;
						cout << 'A';
						A ^= 1;
					} else {
						vis[x] = 2;
						cout << 'B';
						A ^= 1;
					}
				} else {
					if ( vis[x] == 1 )	cout << 'B';
					else	cout << 'A';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}

