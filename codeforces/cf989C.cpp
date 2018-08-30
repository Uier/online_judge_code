#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,char> pic;
char G[55][55];
int n[5];
pic m[5];
void solve(char w, char x, char y, char z) {
	
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	for ( int i=0; i<4; ++i ) {
		cin >> n[i];
		m[i] = pic{n[i],('a'+i)};
	}
	sort(m,m+4);
	solve(m[3].second,m[2].second,m[1].second,m[0].second);
	return 0;
}

