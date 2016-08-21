#include<iostream>
using namespace std;
int par[100001]={0};

void init(int a)
{
	for ( int i=1; i<=a; i++ )
		par[i] = i;
}

int find(int x)
{
	if ( par[x] == x )
		return x;
	return par[x] = find(par[x]);
}

void union_(int x, int y)
{
	par[find(y)] = find(x);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, x, y;
	cin >> t;
	while ( t-- )
	{
		par[100001]={0};
		cin >> n >> m;
		init(n);
		while ( m-- )
		{
			cin >> x >> y; // y¿éµ¹x;
			union_(x, y);
		}
		for ( int i=1; i<=n; i++ )
			cout << find(par[i]) << '\n';
	}
	return 0;
}

