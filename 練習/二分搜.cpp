#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a=0,z=14;
	int x[15] = {9,9,1,5,5,3,3,8,8,13,15,1,2,2,1};
	sort(x,x+15);
	for ( int i=0; i<15; i++ ) cout << x[i] << ' ';
	cout << '\n' << '\n';
	int n,mid=0;
	while ( cin >> n )
	{
		a=0,z=14,mid=0;
		bool y=0;
		while ( y == 0 )
		{	
			cout<<"test  a="<<a<<"   z="<<z<<endl;
			mid = (a+z) / 2;
			if ( n > x[mid] )
				a = mid+1;
			else if ( n < x[mid] )
				z = mid-1;
			else
			{
				y = 1;
				cout << "exist" << endl;
			}
			if ( a == z )
			{
				cout << "doesn't exist" << endl;
				break;
			}
		}
	}
	return 0;
}

