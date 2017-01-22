#include<iostream>
using namespace std;
int bg[500][500];
bool bbgg[500][500]={false};
int main()
{
	int n;
	for ( int i=0; i<n; i++ )
	{
		for ( int j=0; j<n; j++ )
		{
			cin >> bg[i][j];
			if ( bg[i][j] == '*' )
				bbgg[i][j] = true;
		}	
	}
	for ( int i=0; ; i++ )
	{
		int a;
		cin >> a;
		if ( a == 0 )
			break;
		else
		{
			for ( int j=0; j<n; j++ )
			{
				for ( int k=0; k<n; k++ )
				{
					if (bg[j][k] == a)
						bbgg[j][k] = true;
					cout << "HI" << endl;
				}
			}
		}
	}
	int ans=0, jdg=0;
	for ( int i=0; i<n; i++ )
	{
		jdg=0;
		for ( int j=0; j<n; j++ )
		{
			if ( bbgg[i][j] )
			{
				jdg++;
				cout << "i= " << i << " j= " << j << endl;
			}
		}
		if ( jdg == n )
			ans++;
	}
	for ( int i=0; i<n; i++ )
	{
		jdg=0;
		for ( int j=0; j<n; j++ )
		{
			if ( bbgg[j][i] )
			{
				jdg++;
				cout << "i= " << i << " j= " << j << endl;
			}
		}
		if ( jdg == n )
			ans++;
	}
	jdg=0;
	for ( int i=0; i<n; i++ ) 
	{
		if ( bbgg[i][i] )
		{
			jdg++;
			cout << "i= " << i << " j= " << i << endl;
		}
	}
	if ( jdg == n )
		ans++;
	for ( int i=0; i<n; i++ )
	{
		for ( int j=0; j<n; j++ )
		{
			if ( bbgg[i][j] )
				cout << "true" << ' ';
			else
				cout << "fals" << ' ';
		}
		cout << endl;
	}
		
	
	cout << ans << endl;
	return 0;
}

