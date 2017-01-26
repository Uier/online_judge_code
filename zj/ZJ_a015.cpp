#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int x, y;
	while ( scanf("%d %d", &x, &y) != EOF )
	{
		int arr[x][y];
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				scanf("%d", &arr[i][j]);
		for (int j = 0; j < y; ++j)
		{
			for (int i = 0; i < x; ++i)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
	}
	return 0;
}