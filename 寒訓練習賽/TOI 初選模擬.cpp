#include<iostream>
using namespace std;
char ans[101];
int main()
{
	string l, n;
	getline(cin,l);
	int len=l.size();
	cin >> n;
	int ls=n.size(), total=0, z=0;
	int y=0;
	for ( int i=0; i<len; i++ )
	{
		if ( y == i )
		{
			for ( int j=0; j<ls; j++ )
			{
				if ( l[i] == ' ' )
				{
					ans[z] = l[i];
					z++;
					y++;
					break;
				}
				if ( l[i] == n[j] )
				{
					ans[z] = l[i];
					z++;
					y++;
					break;
				}
			}
		}
	}
	for ( int i=z-1; i>=0; i--)
	{
		if ( ans[i] == ' ' )
			z--;
		else
			break; 
	}
	for ( int i=0; i<z; i++ )
		cout << ans[i];
	cout << endl;
	return 0;
}

