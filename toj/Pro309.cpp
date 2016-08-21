#include <iostream>
#include <set>
using namespace std;
int p[100010];
bool cycle[100010];
int find(int x) {
	return (p[x]==x) ? x : (p[x]=find(p[x]));
}
void union_(int x, int y) {
	p[find(x)] = find(y);
}
set<pair<int,int>> st;
int main(int argc, char const *argv[])
{
	int n, q;
	cin >> n >> q;
	for ( int i=0; i<n; i++ ){
		cycle[i] - false;
		p[i] = i;
	}
	while ( q-- )
	{
		int a, b;
		char c;
		cin >> c;
		if ( c=='L' )
		{
			cin >> a >> b;
			if ( a!=b && st.find({a,b})==st.end() )
			{
				st.insert({a,b});
				st.insert({b,a});
				if ( find(a)==find(b) )
					cycle[find(a)] = true;
				else {
					cycle[find(b)] |= cycle[find(a)];
					union_(a,b);
				}
			}
		}
		else
		{
			cin >> a;
			if ( cycle[find(a)] )
				cout << a << " is team\n";
			else
				cout << a << " is lone\n";
		}
	}
	for ( int i=0; i<n; i++ )
		cout << find(i) << ' ' << cycle[i] << endl;
	return 0;
}