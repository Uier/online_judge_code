#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,t,a,b,d=0; // n 資料數   t 指令數   a b 指令 
	cin >> n;
	int da[n];
	for (int i=0;i<n;i++)
	{
		cin >> da[i];
	}
	cin >> t;
	for (int j=0;j<t;j++)
	{
		cin >> a >> b;
		if ( abs(a-b) > 8 )
		{
			d = 10;
		}
		else if (d != 10)
		{
			int tu;
			tu = da[a-1];
			da[a-1] = da[b-1];
			da[b-1] = tu;
		}
	}
	if ( d != 10 )
	{
		cout << "SORTED!" << endl;
		for (int l=0;l<n-1;l++)
		{
			cout << da[l] << ' ';
		}
		cout << da[n-1] << endl;
	}
	else
	{
		cout << "I QUIT!" << endl;
		for (int k=0;k<n-1;k++)
		{
			cout << da[k] << ' ';
		}
		cout << da[n-1] << endl;
	}
	return 0;
}
