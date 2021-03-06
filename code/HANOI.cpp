#include<iostream>
using namespace std;
//	### AC code 20160601 pm11:41 by uier
void hanoi(int n, int a, int b, int c)  {
	if ( n == 1 ) {
		printf("Move disk from bar #%d to bar #%d.\n", a, c);
		return;
	}
	hanoi(n-1, a, c, b);
	hanoi(1, a, b, c);
	hanoi(n-1, b, a, c);
}
int main() {
	int n;
	scanf("%d\n", &n);
	hanoi(n, 1, 2, 3);
	return 0;
}
