#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> g[10002];
set<pair<int,int>> u;
struct s{
	bool used, odd, even;
};
int x=1;
int dfs(int n)
{
	for ( int i : g[n] )
	{
		if ( x%2 )
			s[i].odd = true;
		else
			s[i].even = true;
		if ( !s[i].used )
		{
			s[i].used = true;
			x++;
			dfs(i);
		}
		x--;
	}
}
int main()
{
	int n, e;
	while ( cin >> n >> e )
	{
		if ( !n )
			break;
		for ( int i=0; i<n; i++ )
		{
			s[i].used = false;
			s[i].odd = false;
			s[i].even = false;
			g[i].clear();
		}
		u.clear();
		while ( e-- )
		{
			int a, b;
			cin >> a >> b;
			if ( a!=b && u.find({a,b})==u.end() )
			{
				u.insert({a,b});
				u.insert({b,a});
				g[b].push_back(a);
			}
		}
		dfs(n);
	}
	return 0;
}
