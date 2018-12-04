#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp = 0, mx = 0, len = 0, cnt_s = 0;
	string s;
	cin >> n >> s;
	len = s.size();
	for ( int i=0; i<len; ++i ) {
		if ( s[i] == 'G' ) {
			tmp++;
		} else {
			mx = max(mx,tmp);
			arr.emplace_back(tmp);
			tmp = 0;
			cnt_s++;
		}
	}
	mx = max(mx,tmp);
	arr.emplace_back(tmp);
	int cnt = 0;
	for ( int i : arr )
		if ( i ) {
			cnt++;
		}
	if ( cnt == 0 ) {
		cout << 0 << '\n';
	} else if ( cnt == 1 ) {
		cout << mx << '\n';
	} else if ( cnt == 2 ) {
		bool flag = false;
		for ( int i=1; i<len-1; ++i )
			if ( s[i] == 'S' && s[i-1] == 'G' && s[i+1] == 'G' ) {
				flag = true;
			}
		if ( flag ) {
			cout << n-cnt_s << '\n';
		} else {
			cout << mx+1 << '\n';
		}
	} else if ( cnt > 2 ) {
		int ans = -1;
		for ( int i=1; i<len-1; ++i ) {
			if ( s[i] == 'S' && s[i-1] == 'G' && s[i+1] == 'G' ) {
				int l = 0, j = i-1, r = 0;
				while ( j >= 0 && s[j] == 'G' )	l++, j--;
				j = i+1;
				while ( j < len && s[j] == 'G' ) r++, j++;
				if ( ans == -1 || l+r+1 > ans )
					ans = l+r;
			}
		}
		cout << max(ans,mx)+1 << '\n';
	}
	return 0;
}

