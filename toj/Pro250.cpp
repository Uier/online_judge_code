#include<bits/stdc++.h>
using namespace std;

struct ph {
	int x;
	int y;
};

bool operator < (ph a, ph b)
{
	if ( a.y == b.y )
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	int n, q;
	cin >> n >> q;
	
	priority_queue<ph> pq;
		
	while ( q-- )
	{
		int a, b, c;
		cin >> a;
		if ( a == 1 )
		{
			
		}
	}
	
	return 0;
}
