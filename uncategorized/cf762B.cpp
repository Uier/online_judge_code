#include <iostream>
#include <algorithm>
#define maxn 300005
using namespace std;
int arr[maxn*2], brr[maxn*2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, n, apt = 0, bpt = 0;
	cin >> a >> b >> c;
	cin >> n;
	for ( int i=0, x; i<n; ++i ) {
		string s;
		cin >> x >> s;
		if ( s[0] == 'U' )	arr[apt++] = x;
		else	brr[bpt++] = x;
	}
	sort(arr,arr+apt);
	sort(brr,brr+bpt);
	int aed = min(a,apt), bed = min(b,bpt);
	long long ans = 0;
	for ( int i=0; i<aed; ++i )	ans += arr[i];
	for ( int i=0; i<bed; ++i )	ans += brr[i];
	for ( int i=aed; i<apt; ++i )
		brr[bpt++] = arr[i];
	sort(brr+bed,brr+bpt);
	int ced = min(c,bpt-bed);
	for ( int i=0; i<ced; ++i )	ans += brr[bed+i];
	cout << aed+bed+ced << ' ' << ans << '\n';
	return 0;
}

