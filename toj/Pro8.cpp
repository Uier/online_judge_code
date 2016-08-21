#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while ( cin >> n )
	{
		cin.get();
		string s;
		getline(cin,s);
		int len=s.size(), row=0;
		for ( int i=0; i<n; i++ )
			for ( int j=i; j<len; j+=n )
				cout << s[j];
		cout << endl;
	}
	return 0;
}