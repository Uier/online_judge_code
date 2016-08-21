#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int num[1000000];
int main()
{
	int n;
	string s;
	scanf("%d",&n);
	while ( n-- )
	{
		cin >> s;
		int len=s.size(), max=0;
		for ( int i=0; i<len; i++ )
		{
			num[i] = s[i]-'0';
			if ( num[i] != 0 )
				max += num[i];
		}
		sort(num, num+len);
		if ( (num[0] == 0) && (max%3 == 0) )
		{
			for ( int i=len-1; i>=0; i-- )
				cout << num[i];
		}
		else
			cout << -1;
		cout << endl;
	}
	return 0;
}

