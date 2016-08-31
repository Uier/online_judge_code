#include <iostream>
#include <set>
using namespace std;
multiset<int> st;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	while ( cin >> n >> k ) {
		st.clear();
		k = n-k;
		while ( n-- ) {
			int a;
			cin >> a;
			st.insert(a);
		}
		auto i=st.begin();
		while ( k-- )
			i++; 
		cout << *i << '\n';
	}
	return 0;
}

