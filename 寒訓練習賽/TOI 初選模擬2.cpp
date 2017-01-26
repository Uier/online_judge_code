#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len=s.size();
	for ( int i=0; i<len-1; i++ )
		cout << s[i] << ' ';
	cout << s[len-1] << endl;
	return 0;
}

