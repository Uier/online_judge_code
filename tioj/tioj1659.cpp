#include<iostream>
using namespace std;
bool npr[5005];
int main() {
	npr[0] = npr[1] = true;
	for ( int i=2; i<=5000; ++i )
		if ( !npr[i] )
			for ( int j=i+i; j<=5000; j+=i )
				npr[j] = true;
	int n;
	while ( cin >> n ) {
		cout << "primes between 1 ~ " << n << ":";
		for ( int i=2; i<=n; ++i )
			if ( !npr[i] )
				cout << ' ' << i;
		cout << '\n';
	}
	return 0;
}

