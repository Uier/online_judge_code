#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii> PQ;
bool operator < (pii x, pii y) {
	return x.first < y.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s;
	while ( cin >> n >> k && (n||k) && cin >> s ) {
		k = n-k;
		for ( int i=0; i+k<n; ++i )	PQ.push(pii{s[i]-'0',-i});
		string t = "";
		int ptr = n*2;
		for ( int i=0; i<k; ++i ) {
			PQ.push(pii{s[n-k+i]-'0',-(n-k+i)});
			pii tmp = PQ.top();	PQ.pop();
			while ( tmp.second > ptr ) {
				tmp = PQ.top();	PQ.pop();
			}
			t.push_back(char('0'+tmp.first));
			ptr = tmp.second;
		}
		cout << t << '\n';
		while ( !PQ.empty() )	PQ.pop();
	}
	return 0;
}

