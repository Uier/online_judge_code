#include <iostream>
#include <vector>
#define maxn 505
using namespace std;
int arr[maxn];
bool vis[maxn];
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0, sum = 0;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		if ( arr[i] == 1 ) {
			cnt++;
			v.emplace_back(i);
			vis[i] = true;
		}
		sum += arr[i]-2;
	}
	if ( sum < -2 )	cout << "NO\n";
	else {
		int ans;
		if ( cnt > 2 )	ans = n-(cnt-2)-1;
		else ans = n-1;
		cout << "YES " << ans << '\n' << n-1 << '\n';
		if ( cnt >= 2 ) {
			int l = v[0], r = v[1], pt = 1, edge = ans-2;
			while ( vis[pt] && pt <= n )	pt++;
			cout << l << ' ' << pt << '\n';
			arr[l]--;
			arr[pt]--;
			for ( int i=pt+1; i<=n&&edge; ++i ) {
				if ( vis[i] == 1 )	continue;
				cout << pt << ' ' << i << '\n';
				arr[pt]--;
				arr[i]--;
				edge--;
				pt = i;
			}
			cout << pt << ' ' << r << '\n';
			arr[pt]--;
			arr[r]--;
			pt = 1;
			while ( (vis[pt] || arr[pt] == 0) && pt <= n )	pt++;
			for ( int i=2; i<v.size(); ++i ) {
				cout << v[i] << ' ' << pt << '\n';
				arr[pt]--;
				while ( (vis[pt] || arr[pt] == 0) && pt <= n )	pt++;
			}
		} else if ( cnt == 1 ) {
			int pre = v[0];
			for ( int i=1; i<=n; ++i ) {
				if ( vis[i] )	continue;
				cout << pre << ' ' << i << '\n';
				pre = i;
			}
		} else {
			for ( int i=1; i<n; ++i )
				cout << i << ' ' << i+1 << '\n';
		}
	}
	return 0;
}

