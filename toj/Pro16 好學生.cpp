#include<iostream>
using namespace std;

int t, s, q, w;
int mod[15005];
bool st[30005];

void dp()
{
	for ( int i=0; i<30005; i++ )
		st[i] = false;
	for ( int i=0; i<s; i++ )
		for ( int j=s-1; j>i; j-- )
		{
			if ( mod[i] != 0 && mod[j] != 0 )
				st[mod[i]+mod[j]] = true;
			else if ( mod[i] == 0 && mod[j] == 0 )
				st[0] = true;
		}
}

int main()
{
	scanf("%d", &t);
	while ( t-- )
	{
		scanf("%d", &s);
		for ( int i=0; i<s; i++ )
			scanf("%d", &mod[i]);	
		dp();
		scanf("%d", &q);
		while ( q-- )
		{
			scanf("%d", &w);
			if ( w > 30004 )
				printf("So Bad!\n");
			else if ( st[w] )
				printf("Good!\n");
			else
				printf("So Bad!\n");
		}
	}
	return 0;
}

