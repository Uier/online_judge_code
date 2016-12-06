#include <iostream>
#include <math.h>
#include <set> 
using namespace std;
int a[100010], n;
set<int> S;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	long long max=-1, min=1000000001, s=0;
	S.clear();
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> a[i];
		S.insert(a[i]);
		if ( a[i] > max )
			max = a[i];
		if ( a[i] < min )
			min = a[i];
	}
	if ( S.size() <= 2 )
		puts("YES");
	else {
		s = (max+min)/2;
		int x=0, j=0;
		bool ans=true;
		for ( j; j<n&&x==0; j++ )
			if ( s-a[j] != 0 )
				x = abs(s-a[j]);
		for ( int i=j; i<n; i++ )
			if ( s-a[i] != 0 && abs(s-a[i]) != x )
				ans = false;
		if ( ans )
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

