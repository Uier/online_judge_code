#include<iostream>
using namespace std;
int main()
{
	double a[4];
	for ( int i=0; i<4; i++ )
	{
		double x;
		cin >> x;
		a[i] = 1-x/100;
	}
	int ans[4]={0};
	for ( int i=0; i<4; i++ )
	{
		double jdg=a[i];
		while ( jdg > 0.01 )
		{
			jdg *= a[i];
			ans[i]++;
		}
	}
	for ( int i=0; i<4; i++ )
		cout << ans[i]+1 << ' ';
	return 0;
}

