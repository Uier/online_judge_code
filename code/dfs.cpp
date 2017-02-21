#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#define maxn 9
using namespace std;
bool used[maxn];
int level_t;
int level[maxn];
vector<int> v[maxn];

void dfs (int n)
{
	level[n] = level_t;
	cout << n << ' ' << level[n] << endl;
	used[n] = 1;
	for ( int e : v[n] )
	{
		level_t++;
		if ( !used[e] )
			dfs(e);
		cout << "dfs done!" << endl;
		level_t--; 
	} 
}
void articulation_vertex()
{
	memset(level, 0, sizeof(level));
	level_t = 1;
	dfs(0); 
}
int main()
{
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<m; i++ )
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	articulation_vertex();

	
	return 0;
}

