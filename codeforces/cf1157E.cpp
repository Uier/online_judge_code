#include <iostream>
#include <set>
#define maxn 200005
using namespace std;
int arr[maxn];
multiset<int> cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		arr[i] %= n;
	}
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		cnt.insert(x%n);
	}
	for ( int i=0; i<n; ++i ) {
		auto tmp = cnt.lower_bound(n-arr[i]);
		if ( tmp == cnt.end() )	{
			cout << (arr[i]+(*cnt.begin()))%n << ' ';
			cnt.erase(cnt.begin());
		} else {
			cout << (arr[i]+*tmp)%n << ' ';
			cnt.erase(tmp);
		}
	}
	return 0;
}

