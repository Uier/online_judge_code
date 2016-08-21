#include<iostream>
using namespace std;
int main()
{
	string a, b;
	getline(cin,a);
	getline(cin,b);
	string c=a, d=b;
	int la=0, lb=0;
	la = a.size(); 
	lb = b.size();
	for ( int i=0; i<la; i++ )
	{
		int y=int(a[i]);
		if ( y >= 97 )
			a[i] = char(y-32);
	}
	for ( int i=0; i<lb; i++ )
	{
		int y=int(b[i]);
		if ( y >= 97 )
			b[i] = char(y-32);
	}
	if ( (a == "JILL") && (b == "XIPLUS") )
		cout << "Hello, Sister!\nHi, Sister!\n";
	else if ( (b == "JILL") && (a == "XIPLUS") )
		cout << "Hello, Sister!\nHi, Sister!\n";
	else
		cout << "Hello, " << d << "!\n" << "Hi, " << c << "!\n";
	return 0;
}

