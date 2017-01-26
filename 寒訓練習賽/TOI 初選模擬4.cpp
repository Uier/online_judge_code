#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bu[10000]={0}, cu[10000]={0};
vector<int> au[10000];
queue<int> se;
queue<int> te;
int main()
{
	int n, q;
	cin >> n;
	int z=n-1;
	int a, b;
	while ( z-- )
	{
		cin >> a >> b;
		au[a].push_back(b);
	}
	int r, s, ff[10000], d=0;
	for ( int i=0; i<q; i++ )
	{
		cin >> r >> s;
		se.push(r);
		te.push(r);
		bu[10000]={0};
		cu[10000]={0};
		bu[0] = 1;
		cu[0] = 1;
		while ( se.empty() == 0 )
		{
			int x = se.front();
			se.pop();
			ff[d++] = x;
			for ( int y : au[x] )
			{
				if ( bu[y] == 0 )
				{
					bu[y] = true;
					se.push(y);
				}
			}
		}
		while ( te.empty() == 0 )
		{
			int u = te.front();
			se.pop();
			for ( int i=0; i<d; i++ )
			{
				if ( u == ff[i] )
					cout << u << ' ';
			}
			for ( int y : au[x] )
			{
				if ( bu[y] == 0 )
				{
					bu[y] = true;
					se.push(y);
				}
			}
		}
		cout << endl;
	}
	return 0;
}

