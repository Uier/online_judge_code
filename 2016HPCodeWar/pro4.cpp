#include<iostream>
using namespace std;
int main()
{
	double n, a;
	cin >> n >> a;
	double x, y;
	int xx, yy;
	xx = n-a/2+n;
	x = n-a/2+n;
	yy = a/2-n;
	y = a/2-n;
	
	if ( (x == xx) && (y == yy ) && (x >= 0) && (y >= 0) )
		cout << y << ' ' << x << endl;
	else
		cout << "None" << endl;
	return 0;
}

