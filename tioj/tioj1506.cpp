#include<iostream>
using namespace std;
int main()
{
	double a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
//	y = a1x + b1
//	y = a2x + b2
	double x=a1-a2;
	double rt=(b1-b2)*-1;
	printf("%.2lf\n", rt/x);
	double y=rt/x*a1+b1;
	printf("%.2lf\n", y);
	return 0;
}

