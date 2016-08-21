#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while ( n-- )
	{
		set<int> st;
		st.clear();
		int t, maxx=0;
		cin >> t;
		for ( int i=0; i<t; i++ )
		{
			int a;
			cin >> a;
			if ( st.find(a) != st.end() )
			{
				st.clear();
			}
			st.insert(a);
			if ( maxx < st.size() )
				maxx  = st.size();
		}
		cout << maxx << endl;
	}
	return 0;
}