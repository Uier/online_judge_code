#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	long long ans=1;
	if ( a > b )
		swap(a,b);
	for ( int i=a; i<=b; i++ )
		ans *= i;
	cout << ans << endl;
	return 0;
}

