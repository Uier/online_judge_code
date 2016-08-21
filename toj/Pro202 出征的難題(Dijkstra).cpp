#include <bits/stdc++.h>
using namespace std;
 
struct edge {
	int to;
	int cost;
};

bool operator < (edge a, edge b) {
	return a.cost > b.cost;
}
 								//			WRONG Line66~Line78, 問題在於較多的充氣次數剩餘較多now 後面會走更多 
long long d[105];
int now[105];
const long long inf=100000000000;

vector<edge> vt[105];
priority_queue<edge> pq;

int main()
{
	int n, m, s, q, st, ed;
	scanf("%d %d %d", &n, &m, &s);

	for ( int i=0; i<n; i++ ) 
		vt[i].clear();

	for ( int i=0; i<m; i++ )
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back(edge{b,c});
		vt[b].push_back(edge{a,c});
	}
	scanf("%d", &q);
	while ( q-- )
	{
		while ( !pq.empty() )
			pq.pop();
 
		for ( int i=0; i<n; i++ )
		{
			d[i] = inf;
			now[i] = 0;
		}
		
		scanf("%d %d", &st, &ed);
		d[st] = 0;
		now[st] = 0;
		pq.push(edge{st,0});
		while ( pq.size() )
		{
			edge g=pq.top();
			pq.pop();
			int h=g.to;
			if ( g.cost > s )
				continue;
 			for ( int i=0; i<vt[h].size(); i++ )
 			{
				edge f=vt[h][i];
				
				int yn=0;
				if ( f.cost > now[h] )
					yn = 1;
					
				if ( d[f.to] > d[h]+yn && s >= f.cost)
				{
					if ( now[h] < f.cost )
					{
						d[f.to] = d[h]+1;
						now[f.to] = s-f.cost;
					}
					else
					{
						d[f.to] = d[h];
						now[f.to] -= f.cost;
					}
					pq.push(edge{f.to,f.cost});
				}
			}
		}
		if ( d[ed] != inf )
			printf("%d\n", d[ed]);
		else
			printf("Impossible\n");
	}
	return 0;
}
