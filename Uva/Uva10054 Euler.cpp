#include <iostream>
#include <vector>
using namespace std;
vector<int> G[52];
int edge[52][52];
void euler(int s) {
	for ( int i : G[s] )
		if ( edge[s][i]!=0 ) {
			edge[s][i]--;
			edge[i][s]--;
			euler(i);
			cout << i << ' ' << s << '\n';
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, x=0;
	cin >> t;
	while ( t-- ) {
		int n, c;
		cin >> n;
		for ( int i=0; i<52; i++ ){
			G[i].clear();
			for ( int j=0; j<52; j++ )
				edge[i][j] = 0;
		}
		while ( n-- ) {
			int a, b;
			cin >> a >> b;
			c = a;
			edge[a][b]++;
			edge[b][a]++;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		x++;
		cout << "Case #" << x << '\n';
		bool ans=false;
		for ( int i=0; i<52; i++ )
			if ( G[i].size()%2==1 )
				ans = true;
		if ( ans )
			cout << "some beads may be lost\n";
		else 
			euler(c);
		if ( t!=0 )
			cout << '\n';
	}
	return 0;
}

