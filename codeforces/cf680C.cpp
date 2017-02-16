#include <iostream>
#include <vector>
using namespace std;
bool np[50];
vector<int> p; 
int main() {
	fflush(stdout);
	np[0] = np[1] = true;
	for ( int i=2; i<50; i++ )
		if ( !np[i] ) {
			for ( int j=i+i; j<50; j+=i )
				np[j] = true;
			p.push_back(i);
		}
	p.push_back(4);
	p.push_back(9);
	p.push_back(25);
	p.push_back(49);
	int ans = 0, prm = 1;
	string s;
	for ( int i : p ) {
		cout << i << '\n';
		cin >> s;
		if ( s[0] == 'y' )
			ans++;
		if ( ans >= 2 ) {
			prm = 0;
			break;
		}
	}
	if ( prm )
		cout << "prime\n";
	else
		cout << "composite\n";
	return 0;
}

