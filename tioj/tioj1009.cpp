#include <iostream>
using namespace std;
struct data
{
	int hr, min, sec;
};
int main(int argc, char const *argv[])
{
	string a, b;
	cin >> a >> b;
	data x, y, z;
	x.hr = (a[0]-'0')*10+(a[1]-'0');
	y.hr = (b[0]-'0')*10+(b[1]-'0');
	x.min = (a[3]-'0')*10+(a[4]-'0');
	y.min = (b[3]-'0')*10+(b[4]-'0');
	x.sec = (a[6]-'0')*10+(a[7]-'0');
	y.sec = (b[6]-'0')*10+(b[7]-'0');
	if ( y.hr > x.hr )
	{
		y.sec -= x.sec;
		if ( y.sec < 0 )
		{
			y.sec += 60;
			x.min++;
		}	
		y.min -= x.min;
		if ( y.min < 0 )
		{
			y.min += 60;
			x.hr++;
		}
		y.hr -= x.hr;
		z.hr = y.hr;
		z.min = y.min;
		z.sec = y.sec;
	}
	else if ( y.hr == x.hr && y.min > x.min )
	{
		y.sec -= x.sec;
		if ( y.sec < 0 )
		{
			y.sec += 60;
			x.min++;
		}
		y.min -= x.min;
		y.hr -= x.hr;

		z.hr = y.hr;
		z.min = y.min;
		z.sec = y.sec;
	}
	else if ( y.hr==x.hr && y.min==x.min && y.sec>x.sec )
	{
		y.sec -= x.sec;
		y.min -= x.min;
		y.hr -= x.hr;

		z.hr = y.hr;
		z.min = y.min;
		z.sec = y.sec;
	}
	else
	{
		if ( x.sec != 0 )
		{
			x.sec = 60-x.sec;
			x.min++;
		}
		if ( x.min != 0 )
		{
			x.min = 60-x.min;
			x.hr++;
		}
		x.hr = 24-x.hr;
		z.hr = x.hr+y.hr;
		z.min = x.min+y.min;
		z.sec = x.sec+y.sec;
		if ( z.sec >= 60 )
		{
			z.min++;
			z.sec -= 60;
		}
		if ( z.min>= 60 )
		{
			z.hr++;
			z.min -= 60;
		}
	}
	if ( z.hr < 10 )
		cout << 0 << z.hr << ':';
	else
		cout << z.hr << ':';
	if ( z.min < 10 )
		cout << 0 << z.min << ':';
	else
		cout << z.min << ':';
	if ( z.sec < 10 )
		cout << 0 << z.sec << endl;
	else
		cout << z.sec << endl;
	return 0;
}