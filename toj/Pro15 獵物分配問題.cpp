#include<bits/stdc++.h>
using namespace std;

struct data {
	string a;
	int b, c;
}dt[10000];

bool cmp(data x, data y)
{
	if ( x.b == y.b )
	{
		if ( x.b == 5 )
		{
			if ( x.c == y.c )
				return x.a<y.a;
			return x.c<y.c;
		}
		if ( x.c == y.c )
			return x.a<y.a;
		return x.c>y.c;
	}
	return x.b<y.b;
}

int main()
{
	ios::sync_with_stdio(0); // endl ┤лжи '\n' 
	cin.tie(0);
	
	map<char, int> mp;
	mp['e']=1; mp['n']=2; mp['k']=3; mp['w']=4;
	mp['a']=5; mp['m']=6; mp['d']=7; mp['l']=8;
	
	int n, fd, age;
	string name, x;
	while (cin >> n >> fd)
	{
		for ( int i=0; i<n; i++ )
		{
			cin >> name >> x >> age;
			dt[i] = {name, mp[x[0]], age};
		}
		sort(dt, dt+n, cmp);
		if ( fd > n )
			fd = n;
		for ( int j=0; j<fd; j++ )
			cout << dt[j].a << '\n';
	}
	return 0;
}

