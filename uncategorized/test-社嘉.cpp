#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool used[2][4];
void Guess_Number(){
	cout <<"\n�w��Ө�q�Ʀr�A�C���Y�N�}�l�o> <\n\n\n"; 
	Sleep(1000);
	cout <<"���׬ɦb0~1000�����A�п�J�Ʀr\n";
	srand(time(NULL));
	int ans = rand()%1000, choose, cnt = 1, l=0, r=1000;
	bool flag = false;
	while ( !flag ){
		cin >>choose;
		if ( choose > 1000 || choose < 0 )
			cout << "��J���~�A�п�J0~1000�������Ʀr\n\n"; 
		else if ( choose == ans ) { flag = true; cnt++; }
		else {
			if ( choose > ans )		r = choose; 
			else	l = choose;
			cout <<"\n���׬ɦb"<<l <<"��"<< r<< "����\n"; 
			cnt++;
		}
	} 
	cout <<"�o�O��" <<cnt <<"���A���ߧA�q���o> <\n"; 
}
void Guess_AB(){
	cout <<"\n�w��Ө�XA�XB�q�Ʀr�A�C���Y�N�}�l�o> <\n\n\n"; 
	Sleep(1000);
	cout <<"�п�J�}�Y����0���|��Ʀr:\n";
	srand(time(NULL));
	int tmp = rand()%9000+1000, cnt = 0, A = 0, B = 0;
	cout <<"test_ans " << tmp <<'\n';
	stringstream ss;
	string s, ans;
	ss <<tmp; ss >>ans; 
	bool flag = false;
	while ( !flag ){
		cin >>s;
		memset(used, 0, sizeof(used));
		cnt++;
		if ( s.size() != 4 ) {
			cout << "��J���~�A �п�J�}�Y����0���|��Ʀr\n\n"; 
			cnt--;
		}
		else {
			A = 0 , B = 0;
			for ( int i=0; i<4; i++ ){
				if ( s[i] == ans[i] ) {
					A++;
					used[0][i] = true;
					used[1][i] = true;
				}
			}
			for ( int i=0; i<4; i++ ){
				for ( int j=0; j<4; j++ ){
					if ( i != j && s[i] == ans[j] && !used[0][i] && !used[1][j] ) {
						B++;
						break;
					}
				}
			}
			if ( A == 4 ) flag = true;
			else cout <<A <<'A' <<B <<"B\n\n";
		}
	}
	cout << "�o�O��" <<cnt <<"���A���ߧA�q���F> <!!\n"; 
}
int main(){
	cout <<"Loading...\n";
	Sleep(1000);
	cout <<"�b����e���̡A��J������n��Enter��\n\n"; 
	Sleep(1000);
	cout <<"�w��Ө�x�n�k����T��s���A�ǩf�Q������p�C���O > <? \n";
	Sleep(1500);
	cout <<"�q�Ʀr�п�J0�F�XA�XB�q�Ʀr�п�J1 \n"; 
	Sleep(1000);
	bool choose;
	cin >> choose;
	if ( !choose ) Guess_Number();
	else Guess_AB();
	return 0;
}

