const int N = 100, W = 100000;
int cost[N], weight[N];
int c[W + 1];
 
void knapsack(int n, int w)
{
    memset(c, 0, sizeof(c));
 
    for (int i=0; i<n; ++i)
        for (int j = weight[i]; j <= w; ++j)
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
 
    cout << "程蔼基" << c[w];
}
//	--------
const int N = 100, W = 100000;
int cost[N], weight[N];
int c[W + 1];   // 兵皚碞镑
 
void knapsack(int n, int w)
{
    memset(c, 0, sizeof(c));
 
    for (int i = 0; i < n; ++i)
        for (int j = w; j - weight[i] >= 0; --j)    // パ┕玡
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
 
    cout << "程蔼基" << c[w];
}
//	--------
/*
Τ璉ノk魁Ω计 ノ猭
(c[j-weight[i]*k]+cost[i]*k) ;
*/ 
