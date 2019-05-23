#include <iostream>
#include <vector> 
#include <map>
#include <queue>
using namespace std;
map<vector<int>,int> D;
queue<vector<int>> Q;
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	vector<int> st, ed;
	for ( int i=0, x; i<9; ++i ) {
		cin >> x;
		st.emplace_back(x);
	}
	for ( int i=0, x; i<9; ++i ) {
		cin >> x;
		ed.emplace_back(x);
	}
	D[st] = 1;
	Q.push(st);
	while ( !Q.empty() ) {
		vector<int> x = Q.front();	Q.pop();
		int pos = 0, cur = D[x];
		while ( x[pos] )	pos++;
		if ( pos-3 >= 0 ) { // up
			swap(x[pos],x[pos-3]);
			if ( !D[x] ) {
				D[x] = cur + 1;
				if ( x == ed )	break;
				Q.push(x);
			}
			swap(x[pos],x[pos-3]);
		}
		if ( pos%3 != 2 ) { // right
			swap(x[pos],x[pos+1]);
			if ( !D[x] ) {
				D[x] = cur + 1;
				if ( x == ed )	break;
				Q.push(x);
			}
			swap(x[pos],x[pos+1]);
		}
		if ( pos+3 <= 8 ) { // down
			swap(x[pos],x[pos+3]);
			if ( !D[x] ) {
				D[x] = cur + 1;
				if ( x == ed )	break;
				Q.push(x);
			}
			swap(x[pos],x[pos+3]);
		}
		if ( pos%3 != 0 ) { // left
			swap(x[pos],x[pos-1]);
			if ( !D[x] ) {
				D[x] = cur + 1;
				if ( x == ed )	break;
				Q.push(x);
			}
			swap(x[pos],x[pos-1]);
		}
	}
	cout << D[ed]-1 << '\n';
	return 0;
}
