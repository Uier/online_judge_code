#include<bits/stdc++.h>
using namespace std;
int weight[100005], value[100005];
//	�L���I�]���D 
void backpack(int c, int w)
{
	int dp[w+1]={0};	// dp���, �ثe���I�]����.
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
		int n;	// v -> �Ӹ��q, n -> ���~�Ӽ�. 
		cin >> n;
		for ( int i=0; i<n; i++ )
			cin >> weight[i] >> value[i];
		backpack(n, v);
	}
	return 0;
}

