#include<iostream>
using namespace std;
int main()
{
	int a, b;
	while ( cin >> a >> b )
	{
		int sum=0, rc=0;
		if ( a == 0 && b == 0 )
			break;
		while ( a > 0 || b > 0 )
		{
			if ( a%10+b%10+rc/10 >= 10 )
			{
				sum++;
				rc = a%10+b%10+rc/10;
			}
			else
				rc = 0;
			a /= 10;
			b /= 10;
		}
		if ( sum == 0 )
			cout << "No carry operation." << endl;
		else if ( sum != 1 )
			cout << sum << " carry operations."<< endl;
		else
			cout << sum << " carry operation." << endl;
	}
	return 0;
}

