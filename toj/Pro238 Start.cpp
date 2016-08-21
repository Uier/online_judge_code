#include<bits/stdc++.h>
using namespace std;

struct edge {
    int to;
    int cost;
};

vector<edge> vt[10005];

int ans[10005];
int x=0, few, lot;
bool flag=false;

bool dfs(int p, int d, int len)
{
	if ( len > lot )
		return false;
	if ( len >= few )
		return true;
	for ( edge i : vt[p] )
		if ( i.to != d )
		{
			if ( dfs(i.to, p, len+i.cost) )
				return true;
		}
	return false;
}

int main()
{
    int n;
    cin >> n >> few >> lot;
    for ( int i=0; i<10005; i++ )
        ans[i] = 0;
    int m=n-1;
    while ( m-- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        vt[a].push_back(edge{b,c});
        vt[b].push_back(edge{a,c});
    }
    
    if ( dfs(0, 0, 0) )
        cout << "Eat Eat Eat" << endl;
    else
        cout << "Go find other chickens" << endl;
    
    return 0;
}
