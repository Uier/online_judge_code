#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, x, y;
	cin >> n;
	while ( n-- )
	{
		cin >> x >> y;
		if ( x == 0 )
		{
			if ( y%2 == 0 )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if ( x == 1 )
		{
			if ( y == 0 )
				cout << "YES" << endl;
			else
				cout << "NO" << endl; 
		}
		else if ( x < 0 )
		{
			if ( x%2 != 0 )
			{
				if ( (abs(y) >= x*-1) && (y%2 == 0) && (y != 0) )
					cout << "YES" << endl;
				else
					cout << "NO" << endl; 
			}
			else if ( y%2 == 0 )
				cout << "YES" << endl; 
			else if ( (y >= x) && (y <= x*-1) ) 
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			if ( x%2 == 0 )
			{
				if ( (y < 0) && (abs(y) >= x) && (y%2 == 0) )
					cout << "YES" << endl;
				else if ( (y > 0) && (abs(y) > x) && (y%2 == 0) )
					cout << "YES" << endl;
				else
					cout << "NO" << endl; 
			}
			else if ( y%2 == 0 )
				cout << "YES" << endl;
			else if ( (y >= x*-1+1) && (y <= x+1) ) 
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}

