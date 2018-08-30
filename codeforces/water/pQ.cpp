#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int a = v1*s+t1*2, b = v2*s+t2*2;
	if ( a == b )	cout << "Friendship\n";
	else if ( a < b )	cout << "First\n";
	else	cout << "Second\n";
	return 0;
}

