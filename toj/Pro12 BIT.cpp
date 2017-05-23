#include <iostream>
using namespace std;
int N, M, Q, bit[3005][3005];
int sum(int i, int j) {
	if ( j > 0 )	return bit[i][j]+sum(i,j-(j&-j));
	return 0;
}
void add(int i, int j, int x) {
	if ( j > M )	return;
	bit[i][j] += x;
	add(i,j+(j&-j),x);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for ( int i=1; i<=N; ++i )
		for ( int j=1; j<=M; ++j ) {
			int x;
			cin >> x;
			add(i,j,x);
		}
	cin >> Q;
	while ( Q-- ) {
		int a, b, c, d;
		char p;
		cin >> p;
		if ( p == 'C' ) {
			cin >> a >> b >> c;	// exchange time to memory
			add(a,b,c-(sum(a,b)-sum(a,b-1)));
		} else {
			cin >> a >> b >> c >> d;
			int ans = 0;
			for ( int i=a; i<=c; ++i )
				ans += sum(i,d)-sum(i,b-1);
			cout << ans << '\n';
		}
	}
	return 0;
}

