#include<bits/stdc++.h>
using namespace std;

struct edge {
	int to;
	long long cost;
};

bool operator < (edge a, edge b) 
{
	return a.cost > b.cost;	// 維護最大值 
}

const long long inf=1000000000000000;
long long d[1005];

int main()
{
	int dt, eg, st, ed;	
//  (1 <= dt <= 1000, 1 <= eg <= dt*dt, 1 <= st, ed <= dt)
	while ( cin >> dt >> eg >> st >> ed )
	{
		vector<edge> vt[1005];
		for ( int i=0; i<1005; i++ )
			vt[i].clear();
		for ( int i=0; i<eg; i++ )
		{
			int a, b, c;
			cin >> a >> b >> c;
			vt[a].push_back(edge{b,c});
			vt[b].push_back(edge{a,c});
		}
		for ( int i=1; i<=dt; i++ )	// 將點初始化為無限大 
			d[i] = inf;	
		d[st] = 0;	// 起點
		 
		priority_queue<edge> pq;
		pq.push(edge{st,0});
		while ( !pq.empty() )
		{
			edge t=pq.top();
			pq.pop();
			int v=t.to;
			if ( d[v] < t.cost )	
				continue;
			for ( int i=0; i<vt[v].size(); i++ )
			{
				edge u=vt[v][i];
				if ( d[u.to] > d[v]+u.cost ) // relax function
				{
					d[u.to] = d[v]+u.cost;
					pq.push(edge{u.to,d[u.to]});
				}
			}
		}
		if ( d[ed] != inf )
			cout << d[ed] << endl;
		else
			cout << "He is very hot" << endl;
	}
	 
	return 0;
}

