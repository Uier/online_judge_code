#include<iostream>
using namespace std;
int main()
{
	string s, t;
	bool y=1;
	while ( cin >> s >> t )
	{
		int ls=s.size(), lt=t.size(), x=0, j=0;
		if ( ls < lt )
		{	
			for ( int i=0; i<ls; i++ )
			{
				y = 1;
				while ( y && j < lt )
				{
					if ( t[j] == s[i] )
					{
						x++;
						y = 0;
						j++;
					}
					else
						j++;						
				}
			}
		}
		else
		{
			for ( int i=0; i<lt; i++ )
			{
				y = 1;
				while ( y && j < ls )
				{
					if ( t[i] == s[j] )
					{
						x++;
						y = 0;
						j++;
					}
					else
						j++;
				}
			}
		}
		if ( (x == ls) || (x == lt) )
			cout << "Yes" << endl;
		else
			cout << "No" << endl; 
	}
	return 0;
}

