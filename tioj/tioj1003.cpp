#include<iostream>
using namespace std;
int sum = 1;
int f(int x)
{
	if ( x == 0 )
		cout << sum << endl;
	else
	{
		sum += x;
		f(x-1);
	}
}
int main()
{
	int a;
	cin >> a;
	f(a);
	return 0;
}

