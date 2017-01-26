#include <stdio.h>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	int sudoku[9][9];
	int a;
	while ( scanf("%d", &a) != EOF )
	{
		bool yn=true;
		set<int> sudo;
		sudo.clear();
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				sudoku[i][j] = 0;

		for (int i = 0; i < 9; ++i)
		{	
			for (int j= 0; j < 9; ++j)
			{
				if ( i==0 && j==0 )
					sudoku[i][j] = a;
				else
					scanf("%d", &sudoku[i][j]);
				sudo.insert(sudoku[i][j]);
			}
			if ( sudo.size() != 9 )
				yn = false;
			sudo.clear();
		}
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				sudo.insert(sudoku[j][i]);
			if ( sudo.size() != 9 )
				yn = false;
			sudo.clear();
		}
		for (int i = 0; i < 9; i+=3)
		{
			for (int j = 0; j < 9; j+=3)
			{
				for ( int k = j; k < j+3; ++k)
					for (int l = i; l < i+3; ++l)
						sudo.insert(sudoku[k][l]);
				if ( sudo.size() != 9 )
					yn = false;
				sudo.clear();
			}
		}
		if ( yn )
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}