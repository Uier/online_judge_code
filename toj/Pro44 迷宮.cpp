#include<bits/stdc++.h>
using namespace std;

int n, m;
int mp[1001][1001];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
long long d[1001][1001];
const long long inf=10000000000;
struct point{
	int x, y;
};
point st, ed;

long long bfs()
{
	queue<point> que;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			d[i][j] = inf;
	que.push(point{st.x,st.y});
	d[st.x][st.y] = 0;
	
	while ( que.size() )
	{
		point g=que.front();
		que.pop();
		if ( g.x == ed.x && g.y == ed.y )
			break;
		for ( int i=0; i<4; i++ ) 
		{
			int nx=g.x+dx[i], ny=g.y+dy[i];
			if ( nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]==0 && d[nx][ny]==inf )
			{
				que.push(point{nx,ny});
				d[nx][ny] = d[g.x][g.y] + 1;
			}
		}
	}
	return d[ed.x][ed.y];
}

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			scanf("%d", &mp[i][j]);
	scanf("%d %d %d %d", &st.x, &st.y, &ed.x, &ed.y);
	long long res=bfs();
	if ( res == inf )
		printf("-1\n");
	else
		printf("%lld\n", res);
	return 0;
}
