#include <iostream>
#define maxn 2005
#define int long long 
using namespace std;
int arr[maxn], brr[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, sumr = 0, sumc = 0;
	cin >> n >> m;
	for ( int i=1; i<=n; sumr+=arr[i], ++i )	cin >> arr[i];
	for ( int i=1; i<=m; sumc+=brr[i], ++i )	cin >> brr[i];
	cin >> x;
	
	return 0;
}

