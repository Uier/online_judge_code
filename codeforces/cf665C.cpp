#include <iostream>
using namespace std;
bool mod[200005];
int main() {
	int row = 1;
	string s;
	cin >> s;
	s.push_back('A');	
	for ( int i=1; i<s.size(); i++ ) {
		if ( s[i] == s[i-1] )	row++;
		else {
			row -= 1;
			if ( row%2 )
				for ( int j=i-1; j>=i-row; j-=2 )
					while (s[j]==s[j-1]||s[j]==s[j+1])
						if ( s[j]+1 > 122 )	s[j] = (s[j]-25);
						else s[j] = s[j]+1;
			else
				for ( int j=i-2; j>=i-row; j-=2 )
					while (s[j]==s[j-1]||s[j]==s[j+1])
						if ( s[j]+1 > 122 )	s[j] = (s[j]-25);
						else s[j] = s[j]+1;
			row = 1;
		}
	}
	s.pop_back();
	cout << s << '\n';
	return 0;
}

