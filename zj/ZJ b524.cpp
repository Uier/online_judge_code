#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int len=0, ss=0, j=0;
	string s;
	while( cin >> s )
	{
		j = 0;
		len = s.size();
		ss = 0;
		for ( int i=0; i<len; i++ )
		{
			if ( s[i] == 121 )
			{
				if ( i > j )
					ss += i - j;
				else if ( i < j )
					ss += j - i;
				j+=3;
			}
		}
		printf("%d\n",ss);
	}
	return 0;
}

