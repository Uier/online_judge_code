#include <iostream>
#include <vector>
using namespace std;
vector<int> g[5002];
int grp[5002];
bool even[5002];
void euler(int s, int x) {
    grp[s] = x;
    for ( int i : g[s] ) 
        if ( grp[i] == -1 ) 
            euler(i,x);
}    
int main()
{    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ans=0, gnum=0;
    cin >> n >> m;
    while ( m-- ) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for ( int i=0; i<n; i++ ) 
        grp[i] = -1;
    for ( int i=0; i<n; i++ ) 
        if ( grp[i] == -1 ) {
            euler(i,gnum);
            gnum++;
        }
    for ( int i=0; i<n; i++ )
        if ( g[i].size()%2 == 1 ) {
            ans++;
            even[grp[i]] = true;
        }
    ans /= 2;
    if ( gnum != 1 )
		for ( int i=0; i<gnum; i++ )
        	if ( !even[i] ) 
            	ans++;
    cout << ans << '\n';
    return 0;
}
