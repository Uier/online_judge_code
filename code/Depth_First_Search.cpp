#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

bool used[100];
vector<int> vt[100];
void dfs(int n)	// n -> start
{
	cout << n << endl;
	for ( int i : vt[n] )
		if ( !used[i] )
		{
			used[i] = true;
			dfs(i);
		}
}
int main()
{
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ )
	{
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
	}
	memset(used, 0, sizeof(used));
	used[0] = true;
	dfs(0);
	return 0;
}

