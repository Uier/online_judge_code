#include<iostream>
using namespace std;
//	### AC code 20160601 pm11:41 by uier 
void hanoi(int n, int a, int b, int c) 
{	// a為左桿, b為中桿, c為右桿 如果這行聽不懂就直接忽略~
	printf("hanoi(%d,%d,%d,%d):\n", n, a, b, c);	// 輸出呼叫函式的過程
	if ( n == 1 )
		printf("Move disk from bar #%d to bar #%d.\n", a, c);	// 輸出盤子移動的過程 
	else
	{	//	請看 "Line 7" 盤子移動過程為a -> c 這點請注意 以免下面三行都會看不懂
		hanoi(n-1, a, c, b);   //  hanoi的遞迴 如下 
		hanoi(1, a, b, c);     //  每次只看塔的最上面兩層 令a, b 且令三根桿為1, 2, 3 
		hanoi(n-1, b, a, c);   //  a b之移動順序為 a: 1->2 || b: 1->3 || a: 2->3
	} 						   //  然後第三層出現後會以一樣順序往回排過來  
}							   //  如果你聽不懂別傷心 連我自己也不太能理解XD 
int main() 
{
	int n;
	cin >> n;
	hanoi(n, 1, 2, 3);
	return 0;
}

