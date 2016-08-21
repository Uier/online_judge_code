#include<iostream>
using namespace std;
char a[26][26];
void dfs(int n, int i, int j)
{
	a[i][j] = '0';
	if ( i&&a[i-1][j]=='1' )
		dfs(n,i-1,j);
	if ( j&&a[i][j-1]=='1' )
		dfs(n,i,j-1);
	if ( n-i-1&&a[i+1][j]=='1' )
		dfs(n,i+1,j);
	if ( n-j-1&&a[i][j+1]=='1' )
		dfs(n,i,j+1);
	if ( i&&j&&a[i-1][j-1]=='1' )
		dfs(n,i-1,j-1);
	if ( n-i-1&&j&&a[i+1][j-1]=='1' )
		dfs(n,i+1,j-1);
	if ( i&&n-j-1&&a[i-1][j+1]=='1' )
		dfs(n,i-1,j+1);
	if ( n-i-1&&n-j-1&&a[i+1][j+1]=='1' )
		dfs(n,i+1,j+1);
}
int main()
{
	int n, c=1;
	while ( cin >> n )
	{
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				cin >> a[i][j];
		int ans=0;
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				if ( a[i][j]=='1' )
				{
					dfs(n,i,j);
					ans++;
				}
		printf("Image number %d contains %d war eagles.\n", c++, ans);
	}
	return 0;
}

