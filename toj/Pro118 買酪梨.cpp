#include<iostream>
using namespace std;
int main()
{
	int n,q,a,b;
	cin >> n;
	int sstr[n];
	for (int i=0;i<n;i++)
	{
		cin >> sstr[i];
	}
	cin >> q;
	int buy[q][1];
	for (int j=0;j<q;j++)
	{
		cin >> a >>b;
		buy[j][0] = 0;
		for (;a<=b;a++)
		{
			buy[j][0] += sstr[a-1];
		}
	}
	for (int k=0;k<q;k++)
	{
		cout << buy[k][0] << endl;
	}
	return 0;
}
