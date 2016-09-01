#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;
int I[95], n=0;
bool V[95];
string a[30005], s; 
queue<int> Q;
vector<int> G[95];
stack<char> S;
int main()
{	
	while ( cin >> s ) {
		if ( s != "#" ) {
			a[n++] = s;
			if ( n > 1 )
				for ( int j=0; j<min(a[n-1].size(),a[n-2].size()); j++ )
					if ( a[n-2][j] != a[n-1][j] ) {
						G[a[n-1][j]].push_back(a[n-2][j]);
						I[a[n-2][j]]++;
						V[a[n-2][j]] = true;
						V[a[n-1][j]] = true;
						break;
					}
		}
		else {
			for ( int i=0; i<95; i++ )
				if ( I[i] == 0 && V[i] ) {
					Q.push(i);
					V[i] = false;
				}
			while ( !Q.empty() ) {
				int x=Q.front();
				Q.pop();
				S.push(x);
				for ( int i : G[x] )
					I[i]--;
				for ( int i=0; i<95; i++ )
					if ( I[i] == 0 && V[i] ) {
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
			n = 0;
			for ( int i=64; i<95; i++ ) {
				I[i] = 0;
				V[i] = false;
				G[i].clear();			
			}
		}
	}
	return 0;
}

