#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	cout << w1+h1*2+2+w2+h2*2+2+w1-w2 << '\n';
	return 0;
}

