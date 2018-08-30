#include <iostream>
#include <set>
using namespace std;
multiset<int> S;
void calc(int a, int b, int c, int d) {
	int t = a+b*5+c*10+d*50;
	if ( S.find(t) != S.end() )	
		cout << t <<" :: " << a <<' ' << b << ' ' << c << ' ' << d << '\n';
	S.insert(t);
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<=n; ++i )
		for ( int j=0; j<=n; ++j )
			for ( int k=0; k<=n; ++k ) {
				if ( n-i-j-k < 0 )	continue;
				calc(i,j,k,n-i-j-k);
			}
	int j = 1;
	for ( auto i=S.begin(); i!=S.end(); ++i, ++j ) {
		cout << *i << ' ';
		if ( j%5 == 0 )	cout << '\n';
	}
	cout << '\n';
	cout << "ans: " << S.size() << '\n';
	return 0;
}

