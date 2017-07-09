#include <iostream>
#include <vector>
using namespace std;
int N, t[20], a[20];
vector<int> v;
int lis() {
	v.clear();
	v.push_back(t[a[1]]);
	for ( int i=2; i<=N; ++i )
		if ( t[a[i]] > v.back() )
			v.push_back(t[a[i]]);
		else
			*lower_bound(v.begin(),v.end(),t[a[i]]) = t[a[i]];
	return v.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for ( int i=1; i<=N; ++i )
		cin >> t[i];
	int x;
	while ( cin >> x ) {
		a[x] = 1;
		for ( int i=2; i<=N; ++i ) {
			cin >> x;
			a[x] = i;
		}
		cout << lis() << '\n';
	}
	return 0;
}

