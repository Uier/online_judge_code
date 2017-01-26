#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	map<char,int> rome;
	rome['I'] = 1;	rome['V'] = 5;	rome['X'] = 10;
	rome['L'] = 50;	rome['C'] = 100;rome['D'] = 500;
	rome['M'] = 1000;
	string sa, sb;
	while ( 1 )
	{
		cin >> sa;
		if ( sa[0] == '#' )
			break;
		cin >> sb;
		int na[20], nb[20], pa=0, pb=0;
		for (int i = 0; i < 20; ++i)
		{
			na[i] = 0;
			nb[i] = 0;
		}
		for (int i = 0; i < sa.size(); ++i)
		{
			na[i] = rome[sa[i]];
			if ( i )
			{
				if ( na[i] > na[i-1] )
				{	
					if ( na[i]/na[i-1] == 10 )
						na[i] = 8*na[i-1];
					else
						na[i] = 3*na[i-1];
				}
				pa += na[i];
			}
		}
		pa += na[0];
		for (int i = 0; i < sb.size(); ++i)
		{
			nb[i] = rome[sb[i]];
			if ( i )
			{
				if ( nb[i] > nb[i-1] )
				{	
					if ( nb[i]/nb[i-1] == 10 )
						nb[i] = 8*nb[i-1];
					else
						nb[i] = 3*nb[i-1];
				}
				pb += nb[i];
			}
		}
		pb += nb[0];
		int ans=abs(pa-pb), all[4]={0, 0, 0, 0}, x=3;
		if ( ans == 0 )
			cout << "ZERO\n";
		else
		{
			while ( ans > 0 )
			{
				all[x--] = ans%10;
				ans /= 10;
			}
			for (int i = x+1; i < 4; ++i)
			{
				if ( 4-i == 4 )
				{
					while ( all[i]-- )
						cout << 'M';
				}
				else if ( 4-i == 3 )
				{
					if ( all[i] == 4 )
						cout << "CD";
					else if ( all[i] == 9 )
						cout << "CM";
					else if ( all[i] == 5 )
						cout << 'D';
					else if ( all[i] < 5 )
						while ( all[i]-- )
							cout << 'C';
					else
					{
						cout << 'D';
						all[i] -= 5;
						while ( all[i]-- )
							cout << 'C';
					}
				}
				else if ( 4-i == 2 )
				{
					if ( all[i] == 4 )
						cout << "XL";
					else if ( all[i] == 9 )
						cout << "XC";
					else if ( all[i] == 5 )
						cout << 'L';
					else if ( all[i] < 5 )
						while ( all[i]-- )
							cout << 'X';
					else
					{
						cout << 'L';
						all[i] -= 5;
						while ( all[i]-- )
							cout << 'X'; 
					}
				}
				else
				{
					if ( all[i] == 4 )
						cout << "IV";
					else if ( all[i] == 9 )
						cout << "IX";
					else if ( all[i] == 5 )
						cout << 'V';
					else if ( all[i] < 5 )
						while ( all[i]-- )
							cout << 'I';
					else
					{
						cout << 'V';
						all[i] -= 5;
						while ( all[i]-- )
							cout << 'I';
					}
				}
			}
			cout << '\n';
		}
	}
	return 0;
}