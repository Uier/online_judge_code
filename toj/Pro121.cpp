#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ )
	{
		for ( int j=0; j<i; j++ )
			cout << " ";
		for ( int k=2*(n-i)-1; k>0; k-- )
			cout << (char)(64+n-i);
		cout << endl; 
	}
	
 	return 0;
}