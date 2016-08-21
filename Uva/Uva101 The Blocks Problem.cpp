#include<bits/stdc++.h>
using namespace std;

vector<int> pile[30];
int n, pa, pb, ha, hb;

void find( int x, int y, int z )
{
	for ( y=0; y<n; y++ )
	{
		for ( z=0; z<pile[y].size(); z++ )
		{
			if ( pile[y][z] == x )
			{
				pa = y;
				ha = 
			}
		}
	}
}

void remove( int p, int h )

int main()
{
//	key: functions; 
	while ( cin >> n )
	{
		string s1, s2;
		int a, b;
		while ( cin >> s1 >> a >> s2 >> b )
		{
			if ( s1 == "quit" )
				break;
			find(a, pa, ha);
			find(b, pb, hb);
			if ( pa == pb )
				continue; 
			if ( s1 == "move" )
				remove()
		} 
	}
	return 0;
}

