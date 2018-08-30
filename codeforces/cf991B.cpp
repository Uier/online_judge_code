#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a[6]={0,0,0,0,0,0};
	int x;
	double orsum = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		a[x]++;
		orsum += x;
	}
	double sum = orsum/double(n);
	if ( sum >= 4.5 )	cout << 0 << '\n';
	else {
		double de = 4.5-sum;
		double one = 4/(double)n;
		double two = 3/(double)n;
		double thr = 2/(double)n;
		double fur = 1/(double)n;
		double b[6];
		int ans = 0;
		b[1] = de/one;
		if ( b[1] != (int)b[1] )	b[1] = (int)b[1]+1;
		if ( a[1] >= b[1] ) {
			cout << b[1] << '\n';
			return 0;
		}
		ans += a[1];
		orsum += a[1]*4;
		sum = orsum/(double)n;
		de = 4.5-sum;
		b[2] = de/two;
		if ( b[2] != (int)b[2] )	b[2] = (int)b[2]+1;
		if ( a[2] >= b[2] ) {
			cout << ans+b[2] << '\n';
			return 0;
		}
		ans += a[2];
		orsum += a[2]*3;
		sum = orsum/(double)n;
		de = 4.5-sum;
		b[3] = de/thr;
		if ( b[3] != (int)b[3] )	b[3] = (int)b[3]+1;
		if ( a[3] >= b[3] )	{
			cout << ans+b[3] << '\n';
			return 0;
		}
		ans += a[3];
		orsum += a[3]*2;
		sum = orsum/(double)n;
		de = 4.5-sum;
		b[4] = de/fur;
		if ( b[4] != (int)b[4] )	b[4] = (int)b[4]+1;
		cout << ans+b[4] << '\n';
	}
	return 0;
}

