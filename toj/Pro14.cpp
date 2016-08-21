#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int a[200500], b[200500], c[200500];
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	for ( int i=0; i<200500; i++ )
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	if ( s[0] == 'm' )
	{
		string sa, sb;
		cin >> sa >> sb;
		for ( int i=0; i<sa.size(); i++ )
			a[i] = sa[sa.size()-1-i] - '0';
		for ( int i=0; i<sb.size(); i++ )
			b[i] = sb[sb.size()-1-i] - '0';
		for ( int i=0; i<sa.size(); i++ )
			for ( int j=0; j<sb.size(); j++ )
				c[i+j] += a[i]*b[j];
		for ( int i=0; i<sa.size()+sb.size()-3; i++ )
		{
			c[i+1] += c[i]/10;
			c[i] %= 10;
		}
		int x=200499;
		while ( c[x] == 0 )	x--;
		while ( x >= 0 )	printf("%d", c[x--]);
		printf("\n");
	}
	else
	{
		string sa;
		int ib;
		cin >> sa >> ib;
		vector<int> vc;
		vc.clear();
		for ( int i=0; i<sa.size(); i++ )
		{
			a[i] = sa[sa.size()-1-i] - '0';
			vc.push_back(a[i]);
		}
		if ( ib == 0 )
			cout << 1 << endl;
		else if ( ib == 1 )
			cout << sa << endl;
		else
		{
			while ( --ib )
			{
				for ( int i=0; i<vc.size(); i++ )
					for ( int j=0; j<sa.size(); j++ )
					{
						while ( i+j >= vc.size() )
							vc.push_back(0);
						vc[i+j] = vc[i]*a[j];
					}
				cout << vc.size() << endl;
				cout << vc[vc.size()-1] << endl;
				for ( int i=0; i<vc.size()-1; i++ )
				{
					vc[i+1] += vc[i]/10;
					vc[i] %= 10;
				}
				if ( vc[vc.size()-1] >= 10 )
				{
					vc.push_back(vc[vc.size()-1]/10);
					vc[vc.size()-2] %= 10;
				}
				cout << vc.size() << endl;
				cout << vc[vc.size()-1] << endl;
			}
			for ( int i=vc.size()-1; i>=0; i-- )
				printf("%d", vc[i]);
			printf("\n");
		}
	}
	return 0;
}