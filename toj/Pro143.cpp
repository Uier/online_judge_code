#include <iostream>
using namespace std;
bool used[100002];
int par[100002];	// �H��
void init(int x)	// �N�C�ӤH(�@x��)�������]���ۤv 
{
	for ( int i=0; i<x; i++ )	par[i] = i;
}
int find(int x)		// ��Mx�o�ӤH������ 
{
	return (par[x]==x) ? x : (par[x]=find(par[x]));
}
void union_(int x, int y) // �Nx�My���� 
{
	par[find(x)] = find(y);
}
int main()
{
	int n, m; 
	while ( cin >> n >> m )
	{
		init(n);
		bool ans=false;
		while ( m-- )
		{
			int a, b;
			cin >> a >> b;
			if ( find(a) != find(b) ) 
				ans = true;
			else
				union_(a,b);
		}
		if ( ans )
			cout << "YES" << endl;
		else
		{
			int cnt=0;
			for ( int i=0; i<n; i++ )
				if ( !used[i] )
				{
					cnt++;
					used[i] = true;
				}
			if ( cnt > 2 )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	for ( int i=0; i<n; i++ )cout << par[i] << ' ';
	cout << endl;
	}
	return 0;
}
