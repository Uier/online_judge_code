#include<iostream>
#include<algorithm>
using namespace std;
int lcs[4005][4005]={{0}}, t1[4005]={0}, t2[4005]={0};
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	
	for ( int i=0; i<=s1.size(); i++ )
	{
		for ( int j=0; j<=s2.size(); j++ )
		{
			lcs[i][j] = 0;
			t2[j] = 0;
		}
		t1[i] = 0;
	}
	for ( int i=0; i<s1.size(); i++ )
		t1[i] = s1[i];
	for ( int i=0; i<s2.size(); i++ )
		t2[i] = s2[i];
	
	
	for ( int i=1; i<=s1.size()+1; i++ )
	{
		for ( int j=1; j<=s2.size()+1; j++ )
		{
			if ( t1[i-1] == t2[j-1] )
				lcs[i][j] = lcs[i-1][j-1]+1;
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		} 
	}
	
	if ( lcs[s1.size()][s2.size()] == 0 )
		cout << lcs[s1.size()][s2.size()] << '/' << s1.size()+s2.size()<< endl;
	else
	{
		int ans=2*lcs[s1.size()][s2.size()], mom=s1.size()+s2.size();
		int gcd=__gcd(ans, mom);
		cout << ans/gcd << '/' << mom/gcd << endl;
	}
	return 0;
}

