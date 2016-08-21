#include <bits/stdc++.h>
using namespace std;

int n, m, prt[505], sp=-1;

struct edge {
    int u, v, cost;
} g[50005];

bool cmp (edge a, edge b)
{
    return a.cost < b.cost;
}

int find (int x)
{
    if ( prt[x] == x )
        return x;
    return prt[x] = find(prt[x]);
}

void union_ (int x, int y)
{
    prt[find(x)] = find(y);
}

int kruskal()
{
    int ans=0;
    for ( int i=0; i<n; i++ )
        prt[i] = i;
    for ( int i=0; i<m; i++ )
    {
        if ( i != sp )
        {
            edge h=g[i];
            if ( find(h.u) != find(h.v) )
            {
//                cout << '!' << h.u << ' ' << h.v << ' ' << h.cost << endl;;
                union_(h.u, h.v);
                ans += h.cost;
            }
        }
    }
    for ( int i=1; i<n; i++ )
        if ( (find(i-1) != find(i)) )
            return -1;
    return ans;
}

int main()
{
    cin >> n >> m;
    int al=m, sum=0;
    for ( int i=0; i<m; i++ )
    {
        cin >> g[i].u >> g[i].v >> g[i].cost;
        sum += g[i].cost;
    }
    sort(g, g+m, cmp);
    
    int x=kruskal();
//    cout << x << endl;
    for ( int i=0; i<m; i++ )
    {
        sp = i;
        if ( kruskal() == x )
        {
            al--;
            sum -= g[i].cost;
        }
//        cout << kruskal() << endl;
    }
    cout << al << ' ' << sum << endl;
    return 0;
}
