#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<long long> V, S;
map<char,long long> M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	M['+'] = -9e18;	M['-'] = -8e18;
	M['*'] = -7e18;	M['/'] = -6e18;	M['('] = -5e18;
	int t;
	string s;
	cin >> t;
	while ( t-- && cin >> s ) {
		V.clear();	S.clear();
		int len = s.size();
		for ( int i=0; i<len; ++i ) {
			if ( s[i] >= '0' ) {
				long long tmp = 0, base = 10;
				for ( ; i<len; ++i ) {
					if ( s[i] < '0' )	break;
					tmp *= base;
					tmp += (s[i]-'0');
				}
				S.emplace_back(tmp);
				i--;
			} else if ( s[i] == ')' ) {
				while ( V.back() != M['('] ) {
					S.emplace_back(V.back());
					V.pop_back();
				}
				V.pop_back();
			} else if ( s[i] == '(' ) {
				V.emplace_back(M[s[i]]);
			} else if ( s[i] == '+' || s[i] == '-' ) {
				while ( V.size() && (V.back() == M['+'] || V.back() == M['-'] || V.back() == M['*'] || V.back() == M['/']) ) {
					S.emplace_back(V.back());
					V.pop_back();
				}
				V.emplace_back(M[s[i]]);
			} else { // * & /
				while ( V.size() && (V.back() == M['*'] || V.back() == M['/']) ) {
					S.emplace_back(V.back());
					V.pop_back();
				}
				V.emplace_back(M[s[i]]);
			}
		}
		while ( V.size() ) {
			S.emplace_back(V.back());
			V.pop_back();
		}
		for ( long long i : S ) {
			if ( i > -5e18 )	V.emplace_back(i);
			else {
				long long tmp = V.back();
				V.pop_back();
				if ( i == M['+'] )	V.back() += tmp;
				else if ( i == M['-'] )	V.back() -= tmp;
				else if ( i == M['*'] ) V.back() *= tmp;
				else	V.back() /= tmp;
			}
		}
		cout << V.back() << '\n';
	}
	return 0;
}

