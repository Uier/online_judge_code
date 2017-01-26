#include<iostream>
using namespace std;
//	### AC code 20160601 pm11:41 by uier 
void hanoi(int n, int a, int b, int c) 
{	// a������, b������, c���k�� �p�G�o��ť�����N��������~
	printf("hanoi(%d,%d,%d,%d):\n", n, a, b, c);	// ��X�I�s�禡���L�{
	if ( n == 1 )
		printf("Move disk from bar #%d to bar #%d.\n", a, c);	// ��X�L�l���ʪ��L�{ 
	else
	{	//	�Ь� "Line 7" �L�l���ʹL�{��a -> c �o�I�Ъ`�N �H�K�U���T�泣�|�ݤ���
		hanoi(n-1, a, c, b);   //  hanoi�����j �p�U 
		hanoi(1, a, b, c);     //  �C���u�ݶ𪺳̤W����h �Oa, b �B�O�T�ڱ쬰1, 2, 3 
		hanoi(n-1, b, a, c);   //  a b�����ʶ��Ǭ� a: 1->2 || b: 1->3 || a: 2->3
	} 						   //  �M��ĤT�h�X�{��|�H�@�˶��ǩ��^�ƹL��  
}							   //  �p�G�Ať�����O�ˤ� �s�ڦۤv�]���ӯ�z��XD 
int main() 
{
	int n;
	cin >> n;
	hanoi(n, 1, 2, 3);
	return 0;
}

