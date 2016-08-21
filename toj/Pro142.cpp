#include <iostream>
using namespace std;
int main()
{
	char a[3][3], flag=' ';
	for ( int i=0; i<3; i++ )
		for ( int j=0; j<3; j++ )
		{
			cin >> a[i][j];
			if ( a[i][j] == '#' )
				flag = '#';
		}
	for ( int i=0; i<3; i++ )
	{
		if ( a[i][0]==a[i][1]&&a[i][1]==a[i][2] )
		{
			flag = a[i][0];
			break;
		}
		if ( a[0][i]==a[1][i]&&a[1][i]==a[2][i] )
		{
			flag = a[0][i];
			break;
		}
		if ( a[0][0]==a[1][1]&&a[1][1]==a[2][2] )
		{
			flag = a[0][0];
			break;
		} 
		if ( a[0][2]==a[1][1]&&a[1][1]==a[2][0] )
		{
			flag = a[0][2];
			break;
		}
	}
	if ( flag == 'O' )
		cout << "A wins." << endl;
	else if ( flag == 'X' )
		cout << "B wins." << endl;
	else if ( flag == '#' )
		cout << "Playing" << endl; 
	else
		cout << "Draw" << endl;
	return 0;
}

