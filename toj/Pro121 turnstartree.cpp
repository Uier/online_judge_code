#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin >> n;
	m = 64 + n;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<i;j++)
		{
			cout << ' ';
		}
		for (int k=0;k<(n-1-i)*2+1;k++)
		{
			cout << char(m-i);
		}
		cout << endl;
	}
	return 0;
}

