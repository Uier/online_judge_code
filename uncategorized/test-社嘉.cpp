#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool used[2][4];
void Guess_Number(){
	cout <<"\n歡迎來到猜數字，遊戲即將開始囉> <\n\n\n"; 
	Sleep(1000);
	cout <<"答案界在0~1000之間，請輸入數字\n";
	srand(time(NULL));
	int ans = rand()%1000, choose, cnt = 1, l=0, r=1000;
	bool flag = false;
	while ( !flag ){
		cin >>choose;
		if ( choose > 1000 || choose < 0 )
			cout << "輸入錯誤，請輸入0~1000之間的數字\n\n"; 
		else if ( choose == ans ) { flag = true; cnt++; }
		else {
			if ( choose > ans )		r = choose; 
			else	l = choose;
			cout <<"\n答案界在"<<l <<"到"<< r<< "之間\n"; 
			cnt++;
		}
	} 
	cout <<"這是第" <<cnt <<"次，恭喜你猜對囉> <\n"; 
}
void Guess_AB(){
	cout <<"\n歡迎來到幾A幾B猜數字，遊戲即將開始囉> <\n\n\n"; 
	Sleep(1000);
	cout <<"請輸入開頭不為0的四位數字:\n";
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
			cout << "輸入錯誤， 請輸入開頭不為0的四位數字\n\n"; 
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
	cout << "這是第" <<cnt <<"次，恭喜你猜中了> <!!\n"; 
}
int main(){
	cout <<"Loading...\n";
	Sleep(1000);
	cout <<"在執行畫面裡，輸入完成後要按Enter呦\n\n"; 
	Sleep(1000);
	cout <<"歡迎來到台南女中資訊研究社，學妹想玩什麼小遊戲呢 > <? \n";
	Sleep(1500);
	cout <<"猜數字請輸入0；幾A幾B猜數字請輸入1 \n"; 
	Sleep(1000);
	bool choose;
	cin >> choose;
	if ( !choose ) Guess_Number();
	else Guess_AB();
	return 0;
}

