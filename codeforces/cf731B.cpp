#include <iostream>
using namespace std;
int a[200010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	bool ans=true, ansans=true;
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> a[i];
		if ( a[i] == 0 && !ans )
			ansans = false;
		else if ( a[i]%2 )
			ans = !ans;
	}
	if ( ans && ansans )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

