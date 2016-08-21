#include<bits/stdc++.h>
using namespace std;
int weight[100005], value[100005];
//	無限背包問題 
void backpack(int c, int w)
{
	int dp[w+1]={0};	// dp表格, 目前的背包答案.
	for ( int i=0; i<c; i++ )
	{
		for ( int j=weight[i]; j<=w; j++ )
			dp[j] = max(dp[j], dp[j-weight[i]]+value[i]); 
	}
	cout << dp[w] << endl;
}

int main()
{
	int v;
	while ( cin >> v )
	{
		int n;	// v -> 承載量, n -> 物品個數. 
		cin >> n;
		for ( int i=0; i<n; i++ )
			cin >> weight[i] >> value[i];
		backpack(n, v);
	}
	return 0;
}

