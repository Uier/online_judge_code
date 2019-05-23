#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define maxn 100005
using namespace std;
typedef pair<char,int> pci;
int arr[maxn];
vector<pci> hard, tmp;
void fresh() {
	reverse(hard.begin(),hard.end());
	while ( !hard.empty() && hard.back().first != 'h' )
		hard.pop_back();
	while ( !hard.empty() && hard.back().first != 'a' ) {
		if ( hard.back().first == 'h' )	tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( !hard.empty() && hard.back().first != 'r' ) {
		if ( hard.back().first == 'h' || hard.back().first == 'a' )
			tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( !tmp.empty() ) {
		hard.emplace_back(tmp.back());
		tmp.pop_back();
	}
	reverse(hard.begin(),hard.end());
	while ( !hard.empty() && hard.back().first != 'd' )
		hard.pop_back();
	while ( !hard.empty() && hard.back().first != 'r' ) {
		if ( hard.back().first == 'd' )	tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( !hard.empty() && hard.back().first != 'a' ) {
		if ( hard.back().first == 'd' || hard.back().first == 'r' )
			tmp.emplace_back(hard.back());
		hard.pop_back();
	}
	while ( !tmp.empty() ) {
		hard.emplace_back(tmp.back());
		tmp.pop_back();
	}
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 1, ans = 0;
	char h[5] = {' ','h','a','r','d'};
//	bool f[5] = {1,0,0,0,0};
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		if ( cnt < 5 && s[i] == h[cnt] )	cnt++;
		for ( int j=1; j<5; ++j )
			if ( s[i] == h[j] )	hard.emplace_back(pci{s[i],i});
//		for ( int j=1; j<=4; ++j )
//			if ( s[i] == h[j] && f[j-1] ) {
//				hard.emplace_back(pci{s[i],i});
//				f[j] = true;
//			}
	}
	if ( cnt < 5 )	return cout << 0 << '\n', 0;
	fresh();
	while ( !hard.empty() ) {
		for ( pci i : hard )	cout << i.first;
		cout << '\n';
		int cost[5] = {0,0,0,0,0};
		int yee = 1, ter = 0;
		for ( int i=0; i<hard.size(); ++i ) {
			pci x = hard[i];
			ter = i;
			if ( yee == 5 )	break;
			if ( yee < 5 && x.first == h[yee] )	yee++;
			for ( int j=1; j<5; ++j )
				if ( x.first == h[i] )
					cost[i] += arr[x.second];
		}
		int idx = 0;
		for ( int i=1; i<5; ++i )	cout<< cost[i] << ' ';
		cout << '\n';
		for ( int i=1; i<5; ++i )	if ( cost[i] > cost[idx] )	idx = i;
		vector<pci> kk;
		kk.clear();
		for ( int i=0; i<ter; ++i )	if ( hard[i].first != h[idx] )	kk.emplace_back(hard[i]);
		for ( int i=ter; i<hard.size(); ++i )	kk.emplace_back(hard[i]);
		hard = kk;
		ans += cost[idx];
		fresh();
	}
	cout << ans << '\n';
//	for ( pci x : hard )
//		for ( int i=1; i<=4; ++i )
//			if ( x.first == h[i] )
//				cost[i] += arr[x.second];
//	cout << min(cost[1],min(cost[2],min(cost[3],cost[4]))) << '\n';
	return 0;
}


