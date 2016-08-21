#include<iostream>
using namespace std;
int main()
{
	string p;
	cin >> p;
	int flag=1, i=0, tm=0, l=0;
	l = p.size();
	while ( tm <= 10000 )
	{
		if (flag == 1)
		{
			if (p[i] == '0')
			{
				i++;
				flag = 2;
			}
			else
			{
				p[i] = '0';
				i += 2;
				flag = 4;
			}
		}
		else if (flag == 2)
		{
			if (p[i] == '0')
			{
				p[i] = '1';
				i--;
				flag = 4;
			}
			else
			{
				break;
			}
		}
		else if (flag == 3)
		{
			if (p[i] == '0')
			{
				p[i] = '1';
				i += 2;
				flag = 5;
			}
			else
			{
				p[i] = '0';
				i -= 2;
				flag = 1;
			}
		}
		else if (flag == 4)
		{
			if (p[i] == '0')
			{
				p[i] = '1';
				i++;
				flag = 3;
			}
			else
			{
				i++;
				flag = 5;
			}
		}
		else
		{
			if (p[i] == '0')
			{
				i++;
				flag = 1;
			}
			else
			{
				i--;
				flag = 3;
			}
		}
		if ( (i < 0) || (i >= l) )
		{
			break;
		}
		tm++;
	}
	cout << p << endl;
	return 0;
}

