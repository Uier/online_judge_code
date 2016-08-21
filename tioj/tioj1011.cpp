#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long a, b;
	cin >> a >> b;
	int s=0;
	while ( a>b*2 )
	{
		a /= 2;
		s++;
	}
	while ( a*2<b )
	{
		b /= 2;
		s++;
	}
	if ( a < b )
		swap(a,b);
	while ( a!=2*b && a!=2*b+1 && a!=b )
	{
		a /= 2;
		b /= 2;
		s += 2;
	}
	if ( a==b )
		cout << s << endl;
	else 
		cout << s+1 << endl;
	return 0;
}