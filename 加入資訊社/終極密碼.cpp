#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <cstring>
#include <fstream>
#include <iomanip> 
using namespace std;

const int bombnum[6] = {0,20,40,60,80,100};
const int maxn = 200;
const bool cheat = 00;
const int maxlife = 9;

int ans,correct,nowcount,totalcount,useless,flag,life;
int ci;
bool bomb[205];
string recordname[7];
int record[35];

fstream file;

void Line();
void Initial(int I);
void build(int J);
void Record(int K,int N);
void Changerecord(int L,int M,int O);

int main()
{
	srand((unsigned) time (NULL));
	int left,right;

	printf("\t終極密碼 ver1.6  九命闖五關(修復已知BUG、榜單程式碼優化)\n\n");
	printf("(猜數字找出密碼，但踩到炸彈會讓你損失1條命，當生命歸零你就輸了)\n\n"); 
	printf("輸入字母或符號會導致遊戲崩潰，請注意。\n\n");
	printf("製作 : 台南一中資訊社-Snorlax\n");
	Line();
	printf("密碼範圍：%d ~ %d\n",0,maxn);
	Line();	
	system("pause");
	printf("\n遊戲開始\n");
	Line();
	
	for(int ci = 1;ci <= 5;ci ++)	{
		Initial(ci);
		left = 1;
		right = 200;
		while(ans != correct)	{
			nowcount ++;
			totalcount ++;
			if(cheat == 1)	{
				printf("(%d)",correct);	
			}	
			printf("請輸入猜測的數字，當前猜測次數： %d 次，總猜測次數： %d 次。\n",nowcount,totalcount);
			scanf("%d",&ans);
			if(ans > right || ans < left)	{
				printf("\n\n你的輸入不合法 ! 請重新輸入\n");
			}
			else if(bomb[ans] == 1 && life == 1)	{
				Line();
				printf("\n\n你在第 %d 關的第 %d 回合踩中了炸彈。\n",ci,nowcount);
				printf("你的生命已經歸零。\n");
				printf("遊戲結束。\n");
				printf("本關密碼為: %d 。\n",correct);
				Record(0,ci);
				flag = 0;
				printf("\n喜歡我做的小遊戲嗎 ? 想寫出這樣的東西，歡迎加入資訊社!!\n");
				break;
			}
			else if(bomb[ans] == 1)	{
				Line();
				life --;
				printf("\n\n你在第 %d 關的第 %d 回合踩中了炸彈。\n",ci,nowcount);
				printf("你的生命降低了 1 點，當前生命： %d / %d\n",life,maxlife);
				printf("\n當前範圍:%d ~ %d\n",left,right);
			}
		    else if(ans > correct)	{
				printf("\n你輸入的數字大於密碼。\n");
				right = ans - 1; 
				printf("\n當前範圍:%d ~ %d\n",left,right);
			}
			else if(ans < correct)	{
				printf("\n你輸入的數字小於密碼。\n");
				left = ans + 1;
				printf("\n當前範圍:%d ~ %d\n",left,right);
			}
			else if(ci == 5)	{
				printf("\n\n答案正確！你通過了遊戲！\n你總共猜測的次數是%d 次，你剩餘的生命是 %d / %d 。\n",totalcount,life,maxlife);
				Record(1,ci); 
				printf("\n喜歡我做的小遊戲嗎 ? 想寫出這樣的東西，歡迎加入資訊社!!\n");
				break;
			}
			else	{
				printf("\n答案正確!進入下一關!\n");
				Line();
				system("pause");
			}
			Line();
			}
			if(flag == 0)	{
				break;
			}
	}
	return 0;
}	

void Line(){
	printf("--------------------------------\n");
}

void Initial(int I)	{
	ans = 0;
	nowcount = 0;
	flag = 1;
	if(I == 1)	{
		totalcount = 0;
		life = maxlife;
	} 
	memset(bomb,0,sizeof(bomb));
	printf("\n\n\t關卡 %d / 5 , 此次關卡有 %d 顆炸彈。\n\n",I,bombnum[I]);
	Line();
	printf("產生密碼與炸彈中......\n");
	build(I);
	printf("密碼與炸彈已產生完畢！\n");
	Line();
}

void build(int J)	{
	correct = rand()% maxn + 1;
	bomb[correct] = 1;
	for(int j = 1;j <= bombnum[J];j ++)	{
		useless = rand()% maxn + 1;
		if(bomb[useless] == 0)	{
			bomb[useless] = 1;
		}
		else	{
			j --;
		}
	}
	bomb[correct] = 0;
}

void Record(int K,int N)	{
	file.open("record.txt",ios::in);
	for(int i = 1;i <= 25;i ++)	{
		if(i <= 5)	{
			file >> recordname[i];	
		}
		else	{
			file >> record[i - 5];
		}
	}
	file.close();
	Line();
	for(int i = 1;i <= 5;i ++)	{
		cout << "第 " << record[i] << " 名: " << left << setw(14) << recordname[i] << "  (" ;
		if(record[i + 5] == 0)	{
			cout << "於第 " << record[i + 10] << " 關的第 " << record[i + 15] << " 步死亡。)\n"; 
		}
		else	{
			cout << "於第 " << record[i + 10] << " 步通過遊戲，剩餘 " << record[i + 15] << " 點生命。)\n"; 
		}
	} 
	
	for(int i = 1;i <= 5;i ++)	{		//可以排進的名次 
		if(K == 1)	{					//活著 
			if(record[i + 5] == 0 || (record[i + 5] == 1 && record[i + 10] > N ) || (record[i + 5] == 1 && record[i + 10] == N && life >= record[i + 15]))	{
				for(int j = 4;j >= i;j --)	{
					recordname[j + 1] = recordname[j];
				}
				for(int j = 9;j >= i + 5;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 14;j >= i + 10;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 19;j >= i + 15;j --)	{
					record[j + 1] = record[j];
				}
				Changerecord(i,K,N); 
				break;
			} 
		} 
		else	{
			if((record[i + 5] == 0 && N > record[i + 10]) || (record[i + 5] == 0 && N == record[i + 10] && totalcount >= record[i + 15] ))	{
				for(int j = 4;j >= i;j --)	{
					recordname[j + 1] = recordname[j];
				}
				for(int j = 9;j >= i + 5;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 14;j >= i + 10;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 19;j >= i + 15;j --)	{
					record[j + 1] = record[j];
				}
				Changerecord(i,K,N); 
				break;
			}
		}
	}
}
void Changerecord(int L,int M,int O){
	record[L + 5] = M;
	string name;
	Line();
	printf("恭喜！你的成績足以登上榜單，請輸入你的暱稱(請勿過長或不雅)：\n");
	cin >> name;
	recordname[L] = name;
	
	if(M == 1)	{
		record[L + 10] = totalcount;
		record[L + 15] = life;
	}
	else	{
		record[L + 10] = O;
		record[L + 15] = totalcount;
	}
	Line();
	
	printf("新的榜單為：\n");
	for(int i = 1;i <= 5;i ++)	{
		cout << "第 " << record[i] << " 名: " << left << setw(14) << recordname[i] << "  (" ;
		if(record[i + 5] == 0)	{
			cout << "於第 " << record[i + 10] << " 關的第 " << record[i + 15] << " 步死亡。)\n"; 
		}
		else	{
			cout << "於第 " << record[i + 10] << " 步通過遊戲，剩餘 " << record[i + 15] << " 點生命。)\n"; 
		}
	} 
	Line();
	printf("榜單儲存中......\n榜單儲存完畢。\n");
	file.close();
	file.open("record.txt",ios::out);
	for(int i = 1;i <= 25;i ++)	{
		if(i <= 5)	{
			file << recordname[i] << endl;	
		}
		else	{
			file << record[i - 5] << ' ';
		}
	} 
}
