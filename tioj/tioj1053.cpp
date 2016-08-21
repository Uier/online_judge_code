#include<iostream> 
using namespace std;

void day(int a, int b)
{
	a += b;
	b = a%7;
	if ( b == 0 )
		cout << "Sunday" << endl;
	else if ( b == 1 )
		cout << "Monday" << endl;
	else if ( b == 2 )
		cout << "Tuesday" << endl;
	else if ( b == 3 )
		cout << "Wednesday" << endl;
	else if ( b == 4 )
		cout << "Thursday" << endl;
	else if ( b == 5 )
		cout << "Friday" << endl;
	else
		cout << "Saturday" << endl; 
}
int main()
{
	string s;
	int n;
	cin >> s >> n;
	if ( s[0] == 'S' )
	{
		if ( s[1] == 'u' )
			day(0, n);
		else
			day(6, n);
	}
	else if ( s[0] == 'M' )
		day(1, n);
	else if ( s[0] == 'T' )
	{
		if ( s[1] == 'u' )
			day(2, n);
		else
			day(4, n);
	}
	else if ( s[0] == 'W' )
		day(3, n);
	else
		day(5, n); 
	return 0;
}

