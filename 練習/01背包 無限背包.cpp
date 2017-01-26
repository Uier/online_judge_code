const int N = 100, W = 100000;
int cost[N], weight[N];
int c[W + 1];
 
void knapsack(int n, int w)
{
    memset(c, 0, sizeof(c));
 
    for (int i=0; i<n; ++i)
        for (int j = weight[i]; j <= w; ++j)
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
 
    cout << "�̰������Ȭ�" << c[w];
}
//	--------
const int N = 100, W = 100000;
int cost[N], weight[N];
int c[W + 1];   // �@���}�C�N���F
 
void knapsack(int n, int w)
{
    memset(c, 0, sizeof(c));
 
    for (int i = 0; i < n; ++i)
        for (int j = w; j - weight[i] >= 0; --j)    // �ѫ᩹�e
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
 
    cout << "�̰������Ȭ�" << c[w];
}
//	--------
/*
�����I�]��k�������� �A�έ��k
(c[j-weight[i]*k]+cost[i]*k) ;
*/ 
