#include<bits/stdc++.h>
using namespace std;
int main()
{
//	####	####	O(n^2)	####	####
	int n, res=0;
	cin >> n;
	int a[n], dp[n];
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	for ( int i=0; i<n; i++ )
	{
		dp[i] = 1;
		for ( int j=0; j<i; j++ )
		{
			if ( a[j] < a[i] )
				dp[i] = max(dp[i], dp[j]+1);
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
}
//	####	####	O(nlogn)	####	####
void lis(vector<int> &s)
{
	if ( s.size() == 0 )
		return 0;
	vector<int> v;
	v.push_back(s[0]);
	for ( int i=1; i<s.size(); i++ )
	{
		int d=s[i];
		if ( d > v.back() )
			v.push_back(d);
		else
			*lower_bound(v.begin(), v.end(), d) = d;
	}
	return v.size();
} 
