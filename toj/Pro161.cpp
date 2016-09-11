#include <iostream>
using namespace std;
int t, a, b, m, n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		cin >> a >> b >> m >> n;
		int F[n/2+1]={a,b};
		for ( int i=2; i<=n/2; i++ )
			F[i] = (((F[i/2]+F[i/3]+F[i/4])%m)*F[i/5])%m;
		cout << (((F[n/2]+F[n/3]+F[n/4])%m)*F[n/5])%m << '\n';
	}
	return 0;
}

