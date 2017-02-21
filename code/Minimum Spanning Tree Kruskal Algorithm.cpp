#include<bits/stdc++.h>
using namespace std;
#define maxdt 1005
#define maxeg 500005
int dt, eg, pa[maxdt];

struct edge {
	int u, v, cost;	// u, v -> 兩個端點, cost -> 權重. 
} alleg[maxeg];	

bool cmp(edge x, edge y) {
	return x.cost < y.cost;
}

int find(int x) {
	if ( pa[x] == x )
		return x;
	return pa[x] = find(pa[x]);
}

int union_(int x, int y) {
	pa[find(x)] = find(y);
}

int kruskal() {
	int ans=0;
	for ( int i=0; i<dt; i++ )	// 	initialization
		pa[i] = i;
	sort(alleg, alleg+eg, cmp);
	for ( int i=0; i<eg; i++ )
	{
		edge a = alleg[i];
		if ( find(a.u) != find(a.v) )
		{
			union_(a.u, a.v);
			ans += a.cost;
		}
	}
	for ( int i=1; i<dt; i++ )
	{
		if ( find(i-1) != find(i) )
			return -1;
	}
	return ans;
}

int main()
{
	cin >> dt >> eg;
	for ( int i=0; i<eg; i++ )
		cin >> alleg[i].u >> alleg[i].v >> alleg[i].cost;
	cout << kruskal() << endl;
	return 0;
}

