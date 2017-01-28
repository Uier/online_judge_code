#include <iostream>
#include <stack>
using namespace std;
stack<char> pb;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	getline(cin,s);
	while ( n-- ) {
		bool ans=true;
		while ( !pb.empty() )
			pb.pop();
		getline(cin,s);
		if ( s == "" )
			puts("Yes");
		else {
			for ( int i=0; i<s.size(); i++ ) {
				if ( s[i] == '(' || s[i] == '[' )
					pb.push(s[i]);
				else {
					if ( s[i] == ']' ) {
						if ( pb.empty() || pb.top() != '[' ) {
							ans = false;
							break;
						}
						else
							pb.pop();
					}
					else {
						if ( pb.empty() || pb.top() != '(' ) {
							ans = false;
							break;
						}
						else
							pb.pop();
					}
				}
			}
			if ( ans && pb.empty() )
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}

