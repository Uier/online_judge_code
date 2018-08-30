#include <iostream>
#include <queue>
using namespace std;
queue<int> Q[30];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int len = s.size();
	for ( int i=0; i<len; ++i ) {
		Q[s[i]-'a'].push(i);
	}
	int pt = 0;
	for ( int i=0; i<k; ++i ) {
		while ( Q[pt].empty() )	pt++;
		s[Q[pt].front()] = ' ';
		Q[pt].pop();
	}
	string t = "";
	for ( int i=0; i<len; ++i ) {
		if ( s[i] != ' ' )
			t += s[i];
	}
	if ( t.size() )	cout << t << '\n';
	return 0;
}

