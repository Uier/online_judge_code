#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if ( n%10 < 5 )	cout << n-(n%10) << '\n';
	else	cout << n+(10-n%10) << '\n';
	return 0;
}

