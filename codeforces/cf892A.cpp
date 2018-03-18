#include <iostream>
#include <algorithm>
using namespace std;
struct can {
	long long a, b, c, d;
} a[100005];
bool cmp(can x, can y) {
	return x.b < y.b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n;
	long long sum = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i].a;
		sum += a[i].a;
	}
	for ( int i=0; i<n; ++i )	cin >> a[i].b;
	sort(a,a+n,cmp);
	if ( a[n-1].b + a[n-2].b >= sum )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

