#include<iostream>
#include<set>
#include<sstream>
using namespace std;

int main()
{
	set<string> st;
	string s, d;
	while ( getline(cin, s) )
	{
		for ( int i=0; i<s.size(); i++ )
		{
			int b = int(s[i]);
			if ( (b >= 65) && (b <= 90) )
				s[i] = char(b+32);
			else if ( (b < 97) || (b > 122) )
				s[i] = ' ';
		}
		istringstream iss(s);
		string ls;
		while ( iss >> ls )
			st.insert(ls);
	}
	for ( string i : st )
		cout << i << endl;
	return 0;
}

