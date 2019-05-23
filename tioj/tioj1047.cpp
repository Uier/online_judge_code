#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, brr;
inline void modify(int x) {
	while ( !arr.empty() && arr.back() >= x ) {
		brr.emplace_back(arr.back());
		arr.pop_back();
	}
	arr.emplace_back(x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while ( cin >> s && s != "END" ) {
		arr.clear();
		brr.clear();
		int len = s.size();
		for ( int i=0; i<len; ++i ) {
			if ( s[i] == '0' || s[i] == '1' )	brr.emplace_back(s[i]-'0');
			else if ( s[i] == '!' ) {
				brr.emplace_back(0);
				arr.emplace_back(5);
			} else if ( s[i] == '*' ) modify(4);
			else modify(3);
		}
		while ( !arr.empty() ) {
			brr.emplace_back(arr.back());
			arr.pop_back();
		}
		for ( int i : brr ) {
			if ( i <= 1 )	arr.emplace_back(i);
			else {
				if ( i == 3 ) {
					int x = arr.back();	arr.pop_back();	int y = arr.back();	arr.pop_back();
					arr.emplace_back(x|y);
				} else if ( i == 4 ) {
					int x = arr.back();	arr.pop_back();	int y = arr.back();	arr.pop_back();
					arr.emplace_back(x&y);
				} else {
					int x = arr.back();	arr.pop_back();	int y = arr.back();	arr.pop_back();
					arr.emplace_back(x^1);
				}
			}
		}
		cout << arr.back() << '\n';
	}
	return 0;
}

