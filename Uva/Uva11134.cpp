#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> ipr;
int n;
ipr rx[5005], ry[5005];
bool cmp(ipr a, ipr b) {
	if ( a.first == b.first )	return a.second < b.second;
	return a.first < b.first; 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		for ( int i=0; i<n; i++ )
			cin >> rx[i].first >> ry[i].first >> rx[i].second >> ry[i].second;
		sort(rx,rx+n,cmp);
		sort(ry,ry+n,cmp);
		for ( int i=0; i<n; i++ ) {
			
		}
		
	}	
	return 0;
}

