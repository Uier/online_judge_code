#include <iostream>
#include <set>
#include <vector>
#include <string.h>
using namespace std;
typedef pair<char,int> pii;
typedef pair<int,int> rii;
multiset<pii> S;
multiset<rii> D[30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	string s;
	string r[3] = {"", "", ""};
	S.clear();
	for ( int i=0; i<26; ++i )	D[i].clear();
	vector<int> idx[3];
	for ( int i=0; i<3; ++i )	idx[i].clear();
	for ( int i=0; i<3; ++i )	idx[i].emplace_back(0);	
	cin >> n >> q >> s;
	for ( int i=0; i<s.size(); ++i )	S.insert(pii{s[i],i+1});
	char opt, val;
	int id, pos;
	while ( q-- && cin >> opt ) {
		if ( opt == '+' ) {
			cin >> id >> val;
			id--;
			pos = idx[id].back();
			r[id].push_back(val);
			auto tmp = S.lower_bound(pii{val,pos});
			if ( tmp == S.end() || tmp->first != val ) {
				cout << "NO\n";
				D[val-'a'].insert(rii{pos,id});
				idx[id].emplace_back(-1);
			} else {
				cout << "YES\n";
				S.erase(tmp);
				idx[id].emplace_back(tmp->second);
			}
		} else {
			cin >> id;
			id--;
			char tail = r[id].back();
			r[id].pop_back();
			if ( idx[id].back() == -1 ) {
				idx[id].pop_back();
				D[tail-'a'].erase(D[tail-'a'].find(rii{idx[id].back(),id}));
				int f = 0;
				for ( int i=0; i<26; ++i )	if ( D[i].size() != 0 )	f = 1;
				if ( f )	cout << "NO\n";
				else	cout << "YES\n";
			} else {
				if ( D[tail-'a'].size() == 0 ) {
					cout << "YES\n";
					S.insert(pii{tail,idx[id].back()});
					idx[id].pop_back();
				} else {
					auto tmp = D[tail-'a'].begin();
					if ( tmp->second > idx[id].back() ) {
						cout << "NO\n";
						S.insert(pii{tail,idx[id].back()});
					} else {
						for ( int i=1; i<idx[tmp->second].size(); ++i ) {
							if ( idx[tmp->second][i] == -1 && r[tmp->second][i-1] == tail ) {
								idx[tmp->second][i] = idx[id].back();
							}
						}
						idx[id].pop_back();
						D[tail-'a'].erase(tmp);
						int f = 0;
						for ( int i=0; i<26; ++i )	if ( D[i].size() != 0 )	f = 1;
						if ( f )	cout << "NO\n";
						else	cout << "YES\n";
					}
				}
			}
		}
	}
	return 0;
}

