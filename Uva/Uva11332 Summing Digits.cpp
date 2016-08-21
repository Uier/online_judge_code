#include<iostream>
using namespace std;
int main()
{
	int s;
	while ( cin >> s )
	{
		if ( s == 0 )
			break;
		if ( s < 10 )
			cout << s << endl;
		else 
		{
			int sum=0;
			while ( s >= 10 )
			{
				sum = 0;
				while ( s > 0 )
				{
					sum += s%10;
					s /= 10;
				}
				s = sum;
			}
			cout << sum << endl;
		}
	}
	return 0;
}

