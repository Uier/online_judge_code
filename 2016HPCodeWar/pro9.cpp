#include<iostream>
using namespace std;
int main()
{
	int arr[8][8],suma = 0,sumb = 0;
	for(int i = 0;i < 8;i++)
		for(int j = 0;j < 8;j++)
			cin >> arr[i][j];
	
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 7;j++)
		{
			if(arr[i][j] == arr[i][j + 1] + 1 || arr[i][j] == arr[i][j + 1] - 1)
				suma++;
		}
	}
	for(int j = 0;j < 8;j++)
	{
		for(int i = 0;i < 7;i++)
		{
			if(arr[i][j] == arr[i + 1][j] + 1 || arr[i][j] == arr[i + 1][j] - 1)
				sumb++;
		}
	}
	cout << suma << " " << sumb << endl;
	return 0;
}

