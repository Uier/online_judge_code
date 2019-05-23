#include <iostream>
#include <vector> 
#include <algorithm>
#define maxp 10000005
using namespace std;
typedef long long ll;
bool npr[maxp];
int phi[maxp], mx;
vector<int> arr;
inline bool cmp(int x, int y) {
	if ( phi[x] == phi[y] )	return x < y;
	return phi[x] > phi[y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		mx = max(mx,x);
		arr.emplace_back(x);
	}
	npr[0] = npr[1] = true;
	for ( int i=1; i<=mx; ++i )	phi[i] = i;
	for ( ll i=2; i<=mx; ++i )
		if ( !npr[i] ) {
			phi[i]--;
			for ( ll j=i<<1; j<=mx; j+=i ) {
				npr[j] = true;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	nth_element(arr.begin(),arr.begin()+k-1,arr.end(),cmp);
	cout << arr[k-1] << '\n';
	return 0;
}

