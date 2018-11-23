#include <iostream>
using namespace std;
void print(long long s) {
	if ( s == 0 )	return;
	if ( s/10000000 ) {
		print(s/10000000);
		cout << " kuti";
		s %= 10000000;
	}
	if ( s/100000 ) {
		print(s/100000);
		cout << " lakh";
		s %= 100000;
	}
	if ( s/1000 ) {
		print(s/1000);
		cout << " hajar";
		s %= 1000;
	}
	if ( s/100 ) {
		print(s/100);
		cout << " shata";
		s %= 100;
	}
	if ( s )	cout << ' ' << s;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long s, cs = 1;
	while ( cin >> s ) {
		if ( cs/1000 )	cout << cs++ << '.';
		else if ( cs/100 )	cout << ' ' << cs++ << '.';
		else if ( cs/10 )	cout << "  " << cs++ << '.';
		else	cout << "   " << cs++ << '.';
		if ( s ) print(s);
		else	cout << " 0";
		cout << '\n';
	}
	return 0;
}

