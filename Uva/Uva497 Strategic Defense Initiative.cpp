#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
// ²ö¦W¨ä§®WA 
void lis( vector<int> &s, int n )
{
	if ( s.size() == 1 )
	{
		if ( !n )
			printf("Max hits: 1\n%d\n", s[0]);
		else
			printf("Max hits: 1\n%d\n\n", s[0]);
		return;
	}
	vector<int> a;
	a.clear();
	a.push_back(s[0]);
	for ( int i=1; i<s.size(); i++ )
	{
		if ( s[i] > a.back() )
			a.push_back(s[i]);
		else
			*lower_bound(a.begin(), a.end(), s[i]) = s[i];
	}
	printf("Max hits: %d\n", a.size());
	for ( int i : a )
		printf("%d\n", i);
	if ( n )
		printf("\n");
}
int main()
{
	int n;
	scanf("%d\n", &n);
	while ( n-- )
	{
		vector<int> vt;
		vt.clear();
		char str[256];		
		while ( gets(str) )
		{
			if ( int(str[0]) == 0 )
				break;
			int x;
			sscanf(str, "%d", &x);
			vt.push_back(x);
		}
		lis(vt, n);
	}
	return 0;
}

