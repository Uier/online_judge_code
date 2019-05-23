#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
#include <map>
using namespace std;
vector<int> arr;
map<int,bool> dp;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	string s;
	while ( getline(cin,s) ) {
		stringstream ss(s);
		int x, sum = 0;
		while ( ss >> x ) {
			arr.emplace_back(x);
			sum += x;
		}
		dp[0] = 1;
		for ( int i : arr )
			for ( int j=sum/2-i; j>=0; --j )
				if ( dp[j] )
					dp[j+i] = true;
		int pt = sum/2;
		while ( pt > 0 && !dp[pt] )	pt--;
		cout << (long long)(pt)*(long long)(sum-pt) << '\n';
		dp.clear();
		arr.clear();
	}
	return 0;
}

