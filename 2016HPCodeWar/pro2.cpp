#include<iostream>
using namespace std;
int main()
{
	int n;
	double b;
	cin >> n >> b;
	double a[n], w[n];
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	for ( int i=0; i<n; i++ )
		cin >> w[i];
	
	double sum=0;
	for ( int i=0; i<n; i++ )
	{
		sum += a[i]*w[i];
	}
	if ( sum+b >= 0 )
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}

