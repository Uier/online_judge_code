#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	string s;
	while ( cin >> n )
	{
		set<char> st;
		st.clear();
		if ( n == 0 )
			break;
		while ( n-- )
		{
			cin >> s;
			char a=s[0], b=s[s.size()-1];
			if ( st.find(a) != st.end() )
				st.erase(st.find(a));
			else
				st.insert(a);
			if ( st.find(b) != st.end() )
				st.erase(st.find(b));
			else
				st.insert(b);
		}
		if ( st.empty() )
			cout << "OK" << endl;
		else
			cout << "NG" << endl;
	}
	return 0;
}