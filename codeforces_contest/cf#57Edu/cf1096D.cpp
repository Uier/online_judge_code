#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
typedef pair<char,int> pci;
int arr[maxn];
vector<pci> hard, tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 1;
	char h[5] = {' ','h','a','r','d'};
	bool f[5] = {1,0,0,0,0};
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		if ( cnt < 5 && s[i] == h[cnt] )	cnt++;
		for ( int j=1; j<=4; ++j )
			if ( s[i] == h[j] && f[j-1] ) {
				hard.emplace_back(pci{s[i],i});
				f[j] = true;
			}
	}
	if ( cnt < 5 )	return cout << 0 << '\n', 0;
	while ( hard.back().first != 'd' )	hard.pop_back();
	while ( hard.back().first == 'd' ) {
		tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( hard.back().first != 'r' ) {
		if ( hard.back().first == 'd' )	tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( hard.back().first == 'r' ) {
		tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( hard.back().first != 'a' ) {
		if ( hard.back().first == 'd' || hard.back().first == 'r' )
			tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( !tmp.empty() ) {
		hard.emplace_back(tmp.back());
		tmp.pop_back();
	}
	for ( pci x : hard ) {
		cout << x.first;
	}
	cout << '\n';
	int cost[5] = {0,0,0,0,0};
	for ( pci x : hard )
		for ( int i=1; i<5; ++i )
			if ( x.first == h[i] )
				cost[i] += arr[x.second];
	cout << min(cost[1],min(cost[2],min(cost[3],cost[4]))) << '\n';
	return 0;
}


