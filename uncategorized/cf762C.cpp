#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> L, R;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int lens = s.size(), lent = t.size(), ptl = 0, ptr = t.size()-1;
	for ( int i=0; i<lens; ++i )
		if ( ptl < lent && s[i] == t[ptl] ) {
			L.emplace_back(i);
			ptl++;
		}
	for ( int i=lens-1; i>=0; --i )
		if ( ptr >= 0 && s[i] == t[ptr] ) {
			R.emplace_back(i);
			ptr--;
		}
	reverse(R.begin(),R.end());
	int ans = 0, idx = 0, forR = 0;
	for ( int i=0; i<lens; ++i ) {
		int pos1 = lower_bound(L.begin(),L.end(),i)-L.begin();
		int pos2 = upper_bound(R.begin(),R.end(),i)-R.begin();
		if ( pos1+(int)(pos1<L.size()&&L[pos1]==i) == t.size() ) {
			ans = t.size();
			idx = i;
			break;
		}
		if ( R.size()-pos2+(int)(pos2>0&&R[pos2-1]==i) == t.size() ) {
			ans = t.size();
			idx = i;
			forR = 1;
			break;
		}
		int tmp = pos1+R.size()-pos2;
		if ( (pos1 < L.size() && L[pos1] == i) || (pos2 > 0 && R[pos2-1] == i) )
			tmp++;
		if ( tmp > ans ) {
			ans = tmp;
			idx = i;
		}
	}
	int mx = min(ans,(int)t.size()), flag = 0;
	if ( ans ) {
		for ( int i : L ) {
			if ( i > idx || mx == 0 || forR )	break;
			if ( i == idx )	flag = 1;
			cout << s[i];
			mx--;
		}
		for ( int i : R ) {
			if ( i < idx || (i == idx && flag) || mx == 0 )	continue;
			cout << s[i];
			mx--;
		}
		cout << '\n';
	} else	cout << "-\n";
	return 0;
}

