#include <iostream>
#include <vector>
#define int long long
using namespace std;
int a[105], in[105], ans[105];
bool V[105];
vector<int> G[105];
int dfs(int x) {
	V[x] = true;
	int sum = 0;
	int ind = x;
	for ( int i : G[x] ) 
		if ( !V[i] ) {
			int tmp = dfs(i);
			if ( tmp > sum ) {
				ind = i;
				sum = tmp;
			}
		}
	ans[x] = ind;
	return sum+1;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<n; ++j ) {
			if ( i == j )	continue;
			if ( a[i]%3 == 0 && a[i]/3 == a[j] ) {
				G[i].emplace_back(j);
				in[j]++;
			}
			if ( a[i]*2 == a[j] ) {
				G[i].emplace_back(j);
				in[j]++;
			}
			if ( a[j]%3 == 0 && a[j]/3 == a[i] ) {
				G[j].emplace_back(i);
				in[i]++;
			}
			if ( a[j]*2 == a[i] ) {
				G[j].emplace_back(i);
				in[i]++;
			}
		}
	}
	int index = 0;
	for ( int i=0; i<n; ++i ) {
		if ( in[i] == 0 ) {
			index = i;
			break;
		}
	}
	dfs(index);
	for ( int i=0; i<n; ++i ) {
		cout << a[index] << ' ';
		index = ans[index];
	}
	cout << '\n';
	return 0;
}

