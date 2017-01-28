#include <iostream>
#include <set>
using namespace std;
int ml[5], d, n;
bool V[10], V2[10], sol;
typedef pair<int,int> pii;
set<pii> S;
void checkpr() {
	int fir = n*d;
	bool pr = true;
	int vic = fir;
	if ( vic > 98765 || vic < 10234 ) pr = false;
	for ( int i=0; i<10; i++ )	V2[i] = false;
	while ( vic > 0 ) {
		if ( V[vic%10] || V2[vic%10] )	pr = false;
		V2[vic%10] = true;
		vic /= 10;
	}
	if ( pr ) {
		sol = true;
		pii tmp;
		tmp.first = fir;	tmp.second = d;
		S.insert(tmp);
	}
}
void bt(int x) {
	if ( x == 5 ) {
		checkpr();
		return;
	}
	for ( int i=9; i>=0; i-- )
		if ( !V[i] ) {
			V[i] = true;
			d += i*ml[x];
			bt(x+1);
			V[i] = false;
			d -= i*ml[x];
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool fff= false;
	for ( int i=1, j=0; i<=10000; i*=10, j++ )
		ml[j] = i;
	while ( cin >> n && n ) {
		S.clear();
		sol = false;
		if ( fff )	cout << '\n';
		else	fff = true;
		bt(0);
		if ( !sol )	cout << "There are no solutions for " << n << ".\n";
		for ( auto i = S.begin(); i!=S.end(); i++ ) {
			pii tmp = *i;
			cout << tmp.first << " / ";
			if ( tmp.second < 10234 )	cout << 0;
			cout << tmp.second << " = " << n << '\n';
		}
	}
	return 0;
}

