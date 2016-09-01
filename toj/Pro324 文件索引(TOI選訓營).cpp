#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
int in[125];
bool V[125];
queue<int> Q;
vector<int> G[125];
stack<char> S;
int main()
{
	int n;
	string a[30005]; 
	while ( cin >> n && n != 0 ) {
		memset(in, 0, sizeof(in));
		memset(V, false, sizeof(V));
		for ( int i=0; i<125; i++ )	G[i].clear();			
		cin >> a[0];
		for ( int i=1; i<n; i++ ) {
			cin >> a[i];
			for ( int j=0; j<min(a[i-1].size(),a[i].size()); j++ )
				if ( a[i-1][j] != a[i][j] ) {
					G[a[i][j]].push_back(a[i-1][j]);
					in[a[i-1][j]]++;
					V[a[i-1][j]] = true;
					V[a[i][j]] = true;
					break;
				}
		}
		for ( int i=0; i<125; i++ )
			if ( in[i] == 0 && V[i] ) {
				Q.push(i);
				V[i] = false;
			}
		while ( !Q.empty() ) {
			int x=Q.front();
			Q.pop();
			S.push(x);
			for ( int i : G[x] )
				in[i]--;
			for ( int i=0; i<125; i++ )
				if ( in[i] == 0 && V[i] ) {
					Q.push(i);
					V[i] = false;
				}
		}
		while ( !S.empty() ) {
			cout << S.top();
			S.pop();
		}
		if ( n == 1 )
			cout << a[0];
		cout << '\n';
	}
	return 0;
}

