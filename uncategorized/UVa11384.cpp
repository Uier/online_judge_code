#include <iostream>
using namespace std;
int f(int x) {
	if ( x <= 2 )	return x;
	if ( x == 3 )	return 2;
	return f(x/2)+1;
} 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;	
	while ( cin >> n )	cout << f(n) << '\n';
	return 0;
}

