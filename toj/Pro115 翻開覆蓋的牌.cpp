#include<iostream>
using namespace std;
int main()
{
	int n,num;
	string da,name[10];
	for (int p=0;p<10;p++)
	{
		name[p] = "EMPTY";
	}
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> da >> num;
		name[num-1] = da;
	}
	for (int q=0;q<10;q++)
	{
		cout << name[q] << endl;
	}
	return 0;
}

