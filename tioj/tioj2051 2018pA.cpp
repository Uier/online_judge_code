#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int l;
string s, t;
typedef pair<string,int> element;
vector<element> V[300];
//stack<int> num;
bool cmp(element x, element y) {
	return x.first < y.first;
}
int dfs(int x, int dep) { // index & depth
	cout << "x,dep: " << x << ' ' << dep << '\n';
	for ( int i=x; i<l; ++i ) {
		if ( s[i] == '(' ) {
			i = dfs(x+1,dep+1);
		} else if ( s[i] == ')' ) {
			int cnt = 0; // the num after ()
			++i;
			if ( i+1<l && (s[i] >= '0' && s[i] <= '9') ) {
				int j = i;
				while ( j<l && (s[j] >= '0' && s[j] <= '9') ) ++j;
				for ( int k=j-1, b=1; k>=i; --k, b*=10 )
					cnt += (s[k]-'0')*b;
				i = j;
			}
			if ( cnt == 0 )	cnt++;
			while ( !V[dep].empty() ) {
				element tmp = V[dep].back();
				tmp.second *= cnt;
				V[dep].pop_back();
				V[dep-1].emplace_back(tmp);
			}
			return i;
		} else {
			string tmp = ""; // name of element
			if ( s[i] >= 'A' && s[i] <= 'Z' ) {
				tmp.push_back(s[i++]);
				if ( i<l && s[i] >= 'a' && s[i] <= 'z' )
					tmp.push_back(s[i++]);
				else i--;
			}
			cout << "tmp: " << tmp << '\n';
			int cnt = 0; // the num of element
			if ( i+1<l && s[i+1] >= '0' && s[i+1] <= '9' ) {
				int j = i+2;
				while ( j<l && (s[j] >= '0' && s[j] <= '9') ) ++j;
				for ( int k=j-1, b=1; k>i; --k, b*=10 )
					cnt += (s[k]-'0')*b;
				i = j-1;
			}
			if ( cnt == 0 )	cnt++;
			V[dep].emplace_back(element{tmp,cnt}); // push in stack
		}
	}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> t;
	cout << t << '\n';
	s = "(" + t + ")";
	cout << s << '\n';
	l = s.size();
	dfs(0,0);
	sort(V[0].begin(),V[0].end(),cmp);
	for ( int i=0; i<V[0].size(); ++i );
	for ( element i : V[0] )
		cout << i.first << ':' << i.second << '\n';
	return 0;
}

