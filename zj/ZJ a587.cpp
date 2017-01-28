#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m,w[101],p[101];
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>w[i]>>p[i];
		cin>>m;
		int dp[10001]={0};
		for ( int i=0; i<10001; i++ )
			dp[i] = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=m;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
			}
		}
		cout<<dp[m]<<endl;
	}
    return 0;
}